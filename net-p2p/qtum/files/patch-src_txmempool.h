--- src/txmempool.h.orig	2018-01-21 15:28:11 UTC
+++ src/txmempool.h
@@ -231,7 +231,7 @@ struct mempoolentry_txid
 class CompareTxMemPoolEntryByDescendantScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         bool fUseADescendants = UseDescendantScore(a);
         bool fUseBDescendants = UseDescendantScore(b);
@@ -253,7 +253,7 @@ public:
     }
 
     // Calculate which score to use for an entry (avoiding division).
-    bool UseDescendantScore(const CTxMemPoolEntry &a)
+    bool UseDescendantScore(const CTxMemPoolEntry &a) const
     {
         double f1 = (double)a.GetModifiedFee() * a.GetSizeWithDescendants();
         double f2 = (double)a.GetModFeesWithDescendants() * a.GetTxSize();
@@ -268,7 +268,7 @@ public:
 class CompareTxMemPoolEntryByScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double f1 = (double)a.GetModifiedFee() * b.GetTxSize();
         double f2 = (double)b.GetModifiedFee() * a.GetTxSize();
@@ -282,7 +282,7 @@ public:
 class CompareTxMemPoolEntryByEntryTime
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         return a.GetTime() < b.GetTime();
     }
@@ -291,7 +291,7 @@ public:
 class CompareTxMemPoolEntryByAncestorFee
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double aFees = a.GetModFeesWithAncestors();
         double aSize = a.GetSizeWithAncestors();
@@ -314,7 +314,7 @@ public:
 class CompareTxMemPoolEntryByAncestorFeeOrGasPrice
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         bool fAHasCreateOrCall = a.GetTx().HasCreateOrCall();
         bool fBHasCreateOrCall = b.GetTx().HasCreateOrCall();
@@ -801,7 +801,7 @@ typedef std::pair<double, CTxMemPool::tx
 
 struct TxCoinAgePriorityCompare
 {
-    bool operator()(const TxCoinAgePriority& a, const TxCoinAgePriority& b)
+    bool operator()(const TxCoinAgePriority& a, const TxCoinAgePriority& b) const
     {
         if (a.first == b.first)
             return CompareTxMemPoolEntryByScore()(*(b.second), *(a.second)); //Reverse order to make sort less than
