--- src/fork_gc.c.orig	2024-09-12 09:26:06 UTC
+++ src/fork_gc.c
@@ -278,6 +278,7 @@ static void sendHeaderString(ForkGC *gc, void *arg) {
 }
 
 static void sendHeaderString(ForkGC *gc, void *arg) {
+  struct iovec { void *iov_base; size_t iov_len; };
   struct iovec *iov = arg;
   FGC_sendBuffer(gc, iov->iov_base, iov->iov_len);
 }
@@ -294,7 +295,9 @@ static void FGC_childCollectTerms(ForkGC *gc, RedisSea
     RedisModuleKey *idxKey = NULL;
     InvertedIndex *idx = Redis_OpenInvertedIndexEx(sctx, term, strlen(term), 1, NULL, &idxKey);
     if (idx) {
-      struct iovec iov = {.iov_base = (void *)term, termLen};
+      struct iovec { void *iov_base; size_t iov_len; } iov;
+      iov.iov_base = term;
+      iov.iov_len = termLen;
       FGC_childRepairInvidx(gc, sctx, idx, sendHeaderString, &iov, NULL);
     }
     if (idxKey) {
