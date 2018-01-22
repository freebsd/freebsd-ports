--- src/miner.h.orig	2018-01-21 15:27:53 UTC
+++ src/miner.h
@@ -99,7 +99,7 @@ struct modifiedentry_iter {
 // except operating on CTxMemPoolModifiedEntry.
 // TODO: refactor to avoid duplication of this logic.
 struct CompareModifiedEntry {
-    bool operator()(const CTxMemPoolModifiedEntry &a, const CTxMemPoolModifiedEntry &b)
+    bool operator()(const CTxMemPoolModifiedEntry &a, const CTxMemPoolModifiedEntry &b) const
     {
         bool fAHasCreateOrCall = a.iter->GetTx().HasCreateOrCall();
         bool fBHasCreateOrCall = b.iter->GetTx().HasCreateOrCall();
