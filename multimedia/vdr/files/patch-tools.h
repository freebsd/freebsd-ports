--- tools.h.orig	2026-09-26 17:58:30 UTC
+++ tools.h
@@ -10,11 +10,13 @@
 #ifndef __TOOLS_H
 #define __TOOLS_H
 
+#include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <float.h>
 #include <iconv.h>
+#include <limits.h>
 #include <math.h>
 #include <poll.h>
 #include <stdarg.h>
@@ -28,6 +30,24 @@
 #include <sys/types.h>
 #include "thread.h"
 
+#ifndef HOST_NAME_MAX // not defined by all C libraries
+#define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
+#endif
+
+#ifndef O_LARGEFILE // not needed on systems with a 64 bit off_t
+#define O_LARGEFILE 0
+#endif
+
+#ifdef __GLIBC__
+#if !__GLIBC_PREREQ(2, 24) // readdir_r() is deprecated as of GLIBC 2.24
+#define VDR_USE_READDIR_R
+#endif
+#endif
+
+// Some C libraries (e.g. on FreeBSD and macOS) define their own isnumber()
+// macro in <ctype.h>, which would clash with VDR's isnumber() function:
+#undef isnumber
+
 typedef unsigned char uchar;
 
 extern int SysLogLevel;
@@ -464,7 +484,7 @@ class cReadDir {
 private:
   DIR *directory;
   struct dirent *result;
-#if !__GLIBC_PREREQ(2, 24) // readdir_r() is deprecated as of GLIBC 2.24
+#ifdef VDR_USE_READDIR_R
   union { // according to "The GNU C Library Reference Manual"
     struct dirent d;
     char b[offsetof(struct dirent, d_name) + NAME_MAX + 1];
@@ -831,7 +851,7 @@ public:
         data[i] = T(0);
     size = 0;
   }
-  void Sort(__compar_fn_t Compare)
+  void Sort(int (*Compare)(const void *, const void *))
   {
     qsort(data, size, sizeof(T), Compare);
   }
