--- os/utils.c.orig	2007-08-23 15:04:55.000000000 -0400
+++ os/utils.c	2008-02-29 13:11:01.000000000 -0500
@@ -525,7 +525,11 @@
 
 #ifdef MONOTONIC_CLOCK
     struct timespec tp;
+#if defined(__FreeBSD__) && defined(CLOCK_MONOTONIC_FAST)
+    if (clock_gettime(CLOCK_MONOTONIC_FAST, &tp) == 0)
+#else
     if (clock_gettime(CLOCK_MONOTONIC, &tp) == 0)
+#endif
         return (tp.tv_sec * 1000) + (tp.tv_nsec / 1000000L);
 #endif
 
