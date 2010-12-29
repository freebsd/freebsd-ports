--- ./xbmc/lib/libXDAAP/thread.h.orig	2008-12-04 22:22:25.000000000 +0100
+++ ./xbmc/lib/libXDAAP/thread.h	2010-12-01 12:17:34.243841426 +0100
@@ -37,7 +37,7 @@
 #define ts_mutex      pthread_mutex_t
 #define ts_condition  pthread_cond_t
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 	#define PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE 
 #endif 
 	
