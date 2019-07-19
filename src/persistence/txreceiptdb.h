// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2017-2019 The WaykiChain Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PERSIST_RECEIPTDB_H
#define PERSIST_RECEIPTDB_H

#include "commons/serialize.h"
#include "dbaccess.h"
#include "dbconf.h"

#include <map>
#include <set>

#include <vector>

using namespace std;

typedef uint256 TxID;

class CTxReceiptDBCache {
public:
    CTxReceiptDBCache(CDBAccess *pDbAccess) : txReceiptCache(pDbAccess){};

public:
    bool SetTxReceipts(const TxID &txid, const vector<CReceipt> &receipts);

    bool GetTxReceipts(const TxID &txid, vector<CReceipt> &receipts);

    void Flush();

private:
/*       type               prefixType               key                     value                 variable               */
/*  ----------------   -------------------------   -----------------------  ------------------   ------------------------ */
    /////////// SysParamDB
    // txid -> vector<CReceipt>
    CDBMultiValueCache< dbk::TX_RECEIPT,            TxID,                   vector<CReceipt> >     txReceiptCache;
};

#endif // PERSIST_RECEIPTDB_H