--- ./xbmc/linux/PlatformDefs.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/linux/PlatformDefs.h	2012-01-02 10:14:38.000000000 +0100
@@ -43,6 +43,10 @@
 #include <stdio.h>
 #include <sys/sysctl.h>
 #include <mach/mach.h>
+#elif defined(__FreeBSD__)
+#include <stdio.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
 #else
 #include <sys/sysinfo.h>
 #endif
@@ -166,7 +170,7 @@
 #define CALLBACK    __stdcall
 #define WINAPI      __stdcall
 #define WINAPIV     __cdecl
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #define APIENTRY    WINAPI
 #else
 #define APIENTRY
@@ -364,7 +368,16 @@
 #else
 #define fstat64 fstat
 #endif
-#else
+#elif defined(__FreeBSD__)
+typedef int64_t   off64_t;
+typedef off_t     __off_t;
+typedef off64_t   __off64_t;
+typedef fpos_t fpos64_t;
+#define __stat64 stat
+#define stat64 stat
+#define statfs64 statfs
+#define fstat64 fstat
+#else /* !__APPLE__ && !__FreeBSD__ */
 #define __stat64 stat64
 #endif
 
