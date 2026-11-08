--- src/fork_gc.c.orig	2025-05-26 05:26:53 UTC
+++ src/fork_gc.c
@@ -281,6 +281,7 @@ static void sendHeaderString(ForkGC *gc, void *arg) {
 }
 
 static void sendHeaderString(ForkGC *gc, void *arg) {
+  struct iovec { void *iov_base; size_t iov_len; };
   struct iovec *iov = arg;
   FGC_sendBuffer(gc, iov->iov_base, iov->iov_len);
 }
@@ -296,7 +297,9 @@ static void FGC_childCollectTerms(ForkGC *gc, RedisSea
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
