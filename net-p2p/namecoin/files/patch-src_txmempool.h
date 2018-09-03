--- src/txmempool.h.orig	2017-02-05 10:17:27 UTC
+++ src/txmempool.h
@@ -255,7 +255,7 @@ struct mempoolentry_txid
 class CompareTxMemPoolEntryByDescendantScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         bool fUseADescendants = UseDescendantScore(a);
         bool fUseBDescendants = UseDescendantScore(b);
@@ -277,7 +277,7 @@ public:
     }
 
     // Calculate which score to use for an entry (avoiding division).
-    bool UseDescendantScore(const CTxMemPoolEntry &a)
+    bool UseDescendantScore(const CTxMemPoolEntry &a) const
     {
         double f1 = (double)a.GetModifiedFee() * a.GetSizeWithDescendants();
         double f2 = (double)a.GetModFeesWithDescendants() * a.GetTxSize();
@@ -292,7 +292,7 @@ public:
 class CompareTxMemPoolEntryByScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double f1 = (double)a.GetModifiedFee() * b.GetTxSize();
         double f2 = (double)b.GetModifiedFee() * a.GetTxSize();
@@ -306,7 +306,7 @@ public:
 class CompareTxMemPoolEntryByEntryTime
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         return a.GetTime() < b.GetTime();
     }
@@ -315,7 +315,7 @@ public:
 class CompareTxMemPoolEntryByAncestorFee
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double aFees = a.GetModFeesWithAncestors();
         double aSize = a.GetSizeWithAncestors();
