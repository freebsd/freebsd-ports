--- src/txmempool.h.orig	2018-07-31 20:08:28 UTC
+++ src/txmempool.h
@@ -224,7 +224,7 @@ struct mempoolentry_txid
 class CompareTxMemPoolEntryByDescendantScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         bool fUseADescendants = UseDescendantScore(a);
         bool fUseBDescendants = UseDescendantScore(b);
@@ -246,7 +246,7 @@ class CompareTxMemPoolEntryByDescendantScore (public)
     }
 
     // Calculate which score to use for an entry (avoiding division).
-    bool UseDescendantScore(const CTxMemPoolEntry &a)
+    bool UseDescendantScore(const CTxMemPoolEntry &a) const
     {
         double f1 = (double)a.GetModifiedFee() * a.GetSizeWithDescendants();
         double f2 = (double)a.GetModFeesWithDescendants() * a.GetTxSize();
@@ -261,7 +261,7 @@ class CompareTxMemPoolEntryByDescendantScore (public)
 class CompareTxMemPoolEntryByScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double f1 = (double)a.GetModifiedFee() * b.GetTxSize();
         double f2 = (double)b.GetModifiedFee() * a.GetTxSize();
@@ -275,7 +275,7 @@ class CompareTxMemPoolEntryByScore (public)
 class CompareTxMemPoolEntryByEntryTime
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         return a.GetTime() < b.GetTime();
     }
@@ -284,7 +284,7 @@ class CompareTxMemPoolEntryByEntryTime (public)
 class CompareTxMemPoolEntryByAncestorFee
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double aFees = a.GetModFeesWithAncestors();
         double aSize = a.GetSizeWithAncestors();
