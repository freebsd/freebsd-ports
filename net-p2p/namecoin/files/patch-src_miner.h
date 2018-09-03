--- src/miner.h.orig	2017-02-05 10:17:27 UTC
+++ src/miner.h
@@ -73,7 +73,7 @@ struct modifiedentry_iter {
 // except operating on CTxMemPoolModifiedEntry.
 // TODO: refactor to avoid duplication of this logic.
 struct CompareModifiedEntry {
-    bool operator()(const CTxMemPoolModifiedEntry &a, const CTxMemPoolModifiedEntry &b)
+    bool operator()(const CTxMemPoolModifiedEntry &a, const CTxMemPoolModifiedEntry &b) const
     {
         double f1 = (double)a.nModFeesWithAncestors * b.nSizeWithAncestors;
         double f2 = (double)b.nModFeesWithAncestors * a.nSizeWithAncestors;
@@ -88,7 +88,7 @@ struct CompareModifiedEntry {
 // This is sufficient to sort an ancestor package in an order that is valid
 // to appear in a block.
 struct CompareTxIterByAncestorCount {
-    bool operator()(const CTxMemPool::txiter &a, const CTxMemPool::txiter &b)
+    bool operator()(const CTxMemPool::txiter &a, const CTxMemPool::txiter &b) const
     {
         if (a->GetCountWithAncestors() != b->GetCountWithAncestors())
             return a->GetCountWithAncestors() < b->GetCountWithAncestors();
