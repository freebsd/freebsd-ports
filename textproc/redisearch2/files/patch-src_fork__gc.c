--- src/fork_gc.c.orig	2025-03-20 10:46:28 UTC
+++ src/fork_gc.c
@@ -280,6 +280,7 @@ static void sendHeaderString(ForkGC *gc, void *arg) {
 }
 
 static void sendHeaderString(ForkGC *gc, void *arg) {
+  struct iovec { void *iov_base; size_t iov_len; };
   struct iovec *iov = arg;
   FGC_sendBuffer(gc, iov->iov_base, iov->iov_len);
 }
@@ -295,7 +296,9 @@ static void FGC_childCollectTerms(ForkGC *gc, RedisSea
     char *term = runesToStr(rstr, slen, &termLen);
     InvertedIndex *idx = Redis_OpenInvertedIndex(sctx, term, strlen(term), DONT_CREATE_INDEX, NULL);
     if (idx) {
-      struct iovec iov = {.iov_base = (void *)term, termLen};
+      struct iovec { void *iov_base; size_t iov_len; } iov;
+      iov.iov_base = term;
+      iov.iov_len = termLen;
       FGC_childRepairInvidx(gc, sctx, idx, sendHeaderString, &iov, NULL);
     }
     rm_free(term);
