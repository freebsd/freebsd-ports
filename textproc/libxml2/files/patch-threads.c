--- threads.c.orig	2009-11-30 12:43:34.000000000 +0100
+++ threads.c	2009-11-30 12:44:54.000000000 +0100
@@ -26,6 +26,7 @@
 #endif
 #ifdef HAVE_PTHREAD_H
 #include <pthread.h>
+#include <osreldate.h>
 #elif defined HAVE_WIN32_THREADS
 #include <windows.h>
 #ifndef HAVE_COMPILER_TLS
@@ -46,6 +47,11 @@
 
 #ifdef HAVE_PTHREAD_H
 
+#if __FreeBSD_version < 700000
+int pthread_equal() __attribute__ ((weak));
+#define pthread_equal(a,b) ((pthread_equal) ? pthread_equal(a,b) : 1)
+#endif
+
 static int libxml_is_threaded = -1;
 #ifdef __GNUC__
 #ifdef linux
