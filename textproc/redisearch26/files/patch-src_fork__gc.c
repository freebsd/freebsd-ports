--- src/fork_gc.c.orig	2022-08-22 22:56:20 UTC
+++ src/fork_gc.c
@@ -287,6 +287,7 @@ static void sendHeaderString(ForkGC *gc, void *arg) {
 }
 
 static void sendHeaderString(ForkGC *gc, void *arg) {
+  struct iovec { void *iov_base; size_t iov_len; };
   struct iovec *iov = arg;
   FGC_sendBuffer(gc, iov->iov_base, iov->iov_len);
 }
@@ -303,7 +304,9 @@ static void FGC_childCollectTerms(ForkGC *gc, RedisSea
     RedisModuleKey *idxKey = NULL;
     InvertedIndex *idx = Redis_OpenInvertedIndexEx(sctx, term, strlen(term), 1, &idxKey);
     if (idx) {
-      struct iovec iov = {.iov_base = (void *)term, termLen};
+      struct iovec { void *iov_base; size_t iov_len; } iov;
+      iov.iov_base = term;
+      iov.iov_len = termLen;
       FGC_childRepairInvidx(gc, sctx, idx, sendHeaderString, &iov, NULL);
     }
     if (idxKey) {
