--- ./lib/cpluff/libcpluff/cpluff.c.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./lib/cpluff/libcpluff/cpluff.c	2012-01-02 10:14:38.000000000 +0100
@@ -77,6 +77,7 @@
 	return CP_HOST;
 }
 
+#if defined(CP_THREADS) || !defined(NDEBUG)
 CP_HIDDEN void cpi_lock_framework(void) {
 #if defined(CP_THREADS)
 	cpi_lock_mutex(framework_mutex);
@@ -93,6 +94,7 @@
 	framework_locked--;
 #endif
 }
+#endif
 
 static void reset(void) {
 #ifdef CP_THREADS
