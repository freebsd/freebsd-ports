--- src/hybrid_reader.c.orig	2026-06-21 14:21:33 UTC
+++ src/hybrid_reader.c
@@ -274,7 +274,7 @@ static void HR_Abort(void *ctx) {
   hr->base.isValid = 0;
 }
 
-static size_t HR_LastDocId(void *ctx) {
+static t_docId HR_LastDocId(void *ctx) {
   HybridIterator *hr = ctx;
   return hr->lastDocId;
 }
