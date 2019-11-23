--- src/html.c.orig	2019-11-23 18:00:49 UTC
+++ src/html.c
@@ -14,7 +14,7 @@ extern int gettimeofday(struct timeval *tp, void *tzp)
 
 // OSX has no pthread_tryjoin_np, so we can't do our
 // asynchronous timers under OSX, which is really no great loss.
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define pthread_tryjoin_np pthread_join
 #endif
 
