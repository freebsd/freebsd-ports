--- src/fork_gc.c.orig	2020-04-12 11:18:47 UTC
+++ src/fork_gc.c
@@ -282,6 +282,7 @@ done:
 }
 
 static void sendHeaderString(ForkGC *gc, void *arg) {
+  struct iovec { void *iov_base; size_t iov_len; };
   struct iovec *iov = arg;
   FGC_sendBuffer(gc, iov->iov_base, iov->iov_len);
 }
@@ -298,7 +299,9 @@ static void FGC_childCollectTerms(ForkGC *gc, RedisSea
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
