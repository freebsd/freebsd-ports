--- ./xbmc/visualizations/XBMCProjectM/libprojectM/fftsg.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/visualizations/XBMCProjectM/libprojectM/fftsg.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -782,6 +782,16 @@
 #include <stdio.h>
 #include <stdlib.h>
 #define cdft_thread_t HANDLE
+#ifdef __FreeBSD__
+#define cdft_thread_create(thp,func,argp) { \
+    LONG thid; \
+    *(thp) = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) func, (LPVOID) argp, 0, &thid); \
+    if (*(thp) == 0) { \
+        fprintf(stderr, "cdft thread error\n"); \
+        exit(1); \
+    } \
+}
+#else
 #define cdft_thread_create(thp,func,argp) { \
     DWORD thid; \
     *(thp) = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) func, (LPVOID) argp, 0, &thid); \
@@ -790,6 +800,7 @@
         exit(1); \
     } \
 }
+#endif
 #define cdft_thread_wait(th) { \
     WaitForSingleObject(th, INFINITE); \
     CloseHandle(th); \
