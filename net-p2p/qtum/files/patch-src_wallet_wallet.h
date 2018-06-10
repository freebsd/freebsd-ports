--- src/wallet/wallet.h.orig	2018-05-25 13:32:42 UTC
+++ src/wallet/wallet.h
@@ -668,7 +668,130 @@ class CAccountingEntry (private)
     std::vector<char> _ssExtra;
 };
 
+/** Contract book data */
+class CContractBookData
+{
+public:
+    std::string name;
+    std::string abi;
 
+    CContractBookData()
+    {}
+};
+
+class CTokenTx
+{
+public:
+    static const int CURRENT_VERSION=1;
+    int nVersion;
+    std::string strContractAddress;
+    std::string strSenderAddress;
+    std::string strReceiverAddress;
+    uint256 nValue;
+    uint256 transactionHash;
+
+    // Wallet data for token transaction
+    int64_t nCreateTime;
+    uint256 blockHash;
+    int64_t blockNumber;
+    std::string strLabel;
+
+    CTokenTx()
+    {
+        SetNull();
+    }
+
+    ADD_SERIALIZE_METHODS;
+
+    template <typename Stream, typename Operation>
+    inline void SerializationOp(Stream& s, Operation ser_action) {
+        if (!(s.GetType() & SER_GETHASH))
+        {
+            READWRITE(nVersion);
+            READWRITE(nCreateTime);
+            READWRITE(blockHash);
+            READWRITE(blockNumber);
+            READWRITE(LIMITED_STRING(strLabel, 65536));
+        }
+        READWRITE(strContractAddress);
+        READWRITE(strSenderAddress);
+        READWRITE(strReceiverAddress);
+        READWRITE(nValue);
+        READWRITE(transactionHash);
+    }
+
+    void SetNull()
+    {
+        nVersion = CTokenTx::CURRENT_VERSION;
+        nCreateTime = 0;
+        strContractAddress = "";
+        strSenderAddress = "";
+        strReceiverAddress = "";
+        nValue.SetNull();
+        transactionHash.SetNull();
+        blockHash.SetNull();
+        blockNumber = -1;
+        strLabel = "";
+    }
+
+    uint256 GetHash() const;
+};
+
+class CTokenInfo
+{
+public:
+    static const int CURRENT_VERSION=1;
+    int nVersion;
+    std::string strContractAddress;
+    std::string strTokenName;
+    std::string strTokenSymbol;
+    uint8_t nDecimals;
+    std::string strSenderAddress;
+
+    // Wallet data for token transaction
+    int64_t nCreateTime;
+    uint256 blockHash;
+    int64_t blockNumber;
+
+    CTokenInfo()
+    {
+        SetNull();
+    }
+
+    ADD_SERIALIZE_METHODS;
+
+    template <typename Stream, typename Operation>
+    inline void SerializationOp(Stream& s, Operation ser_action) {
+        if (!(s.GetType() & SER_GETHASH))
+        {
+            READWRITE(nVersion);
+            READWRITE(nCreateTime);
+            READWRITE(strTokenName);
+            READWRITE(strTokenSymbol);
+            READWRITE(blockHash);
+            READWRITE(blockNumber);
+        }
+        READWRITE(nDecimals);
+        READWRITE(strContractAddress);
+        READWRITE(strSenderAddress);
+    }
+
+    void SetNull()
+    {
+        nVersion = CTokenInfo::CURRENT_VERSION;
+        nCreateTime = 0;
+        strContractAddress = "";
+        strTokenName = "";
+        strTokenSymbol = "";
+        nDecimals = 0;
+        strSenderAddress = "";
+        blockHash.SetNull();
+        blockNumber = -1;
+    }
+
+    uint256 GetHash() const;
+};
+
 /** 
  * A CWallet is an extension of a keystore, which also maintains a set of transactions and balances,
  * and provides the ability to create new transactions.
@@ -1304,129 +1427,5 @@ bool CWallet::DummySignTx(CMutableTransaction &txNew, 
     }
     return true;
 }
-
-class CTokenInfo
-{
-public:
-    static const int CURRENT_VERSION=1;
-    int nVersion;
-    std::string strContractAddress;
-    std::string strTokenName;
-    std::string strTokenSymbol;
-    uint8_t nDecimals;
-    std::string strSenderAddress;
-
-    // Wallet data for token transaction
-    int64_t nCreateTime;
-    uint256 blockHash;
-    int64_t blockNumber;
-
-    CTokenInfo()
-    {
-        SetNull();
-    }
-
-    ADD_SERIALIZE_METHODS;
-
-    template <typename Stream, typename Operation>
-    inline void SerializationOp(Stream& s, Operation ser_action) {
-        if (!(s.GetType() & SER_GETHASH))
-        {
-            READWRITE(nVersion);
-            READWRITE(nCreateTime);
-            READWRITE(strTokenName);
-            READWRITE(strTokenSymbol);
-            READWRITE(blockHash);
-            READWRITE(blockNumber);
-        }
-        READWRITE(nDecimals);
-        READWRITE(strContractAddress);
-        READWRITE(strSenderAddress);
-    }
-
-    void SetNull()
-    {
-        nVersion = CTokenInfo::CURRENT_VERSION;
-        nCreateTime = 0;
-        strContractAddress = "";
-        strTokenName = "";
-        strTokenSymbol = "";
-        nDecimals = 0;
-        strSenderAddress = "";
-        blockHash.SetNull();
-        blockNumber = -1;
-    }
-
-    uint256 GetHash() const;
-};
-
-class CTokenTx
-{
-public:
-    static const int CURRENT_VERSION=1;
-    int nVersion;
-    std::string strContractAddress;
-    std::string strSenderAddress;
-    std::string strReceiverAddress;
-    uint256 nValue;
-    uint256 transactionHash;
-
-    // Wallet data for token transaction
-    int64_t nCreateTime;
-    uint256 blockHash;
-    int64_t blockNumber;
-    std::string strLabel;
-
-    CTokenTx()
-    {
-        SetNull();
-    }
-
-    ADD_SERIALIZE_METHODS;
-
-    template <typename Stream, typename Operation>
-    inline void SerializationOp(Stream& s, Operation ser_action) {
-        if (!(s.GetType() & SER_GETHASH))
-        {
-            READWRITE(nVersion);
-            READWRITE(nCreateTime);
-            READWRITE(blockHash);
-            READWRITE(blockNumber);
-            READWRITE(LIMITED_STRING(strLabel, 65536));
-        }
-        READWRITE(strContractAddress);
-        READWRITE(strSenderAddress);
-        READWRITE(strReceiverAddress);
-        READWRITE(nValue);
-        READWRITE(transactionHash);
-    }
-
-    void SetNull()
-    {
-        nVersion = CTokenTx::CURRENT_VERSION;
-        nCreateTime = 0;
-        strContractAddress = "";
-        strSenderAddress = "";
-        strReceiverAddress = "";
-        nValue.SetNull();
-        transactionHash.SetNull();
-        blockHash.SetNull();
-        blockNumber = -1;
-        strLabel = "";
-    }
-
-    uint256 GetHash() const;
-};
-
-/** Contract book data */
-class CContractBookData
-{
-public:
-    std::string name;
-    std::string abi;
-
-    CContractBookData()
-    {}
-};
 
 #endif // BITCOIN_WALLET_WALLET_H
