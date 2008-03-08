--- finch/libgnt/gntwm.c.orig	2008-03-08 13:10:52.000000000 -0500
+++ finch/libgnt/gntwm.c	2008-03-08 13:13:56.000000000 -0500
@@ -24,6 +24,12 @@
 
 #ifdef USE_PYTHON
 #include <Python.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if (__FreeBSD_version <= 700032 && (__FreeBSD_version >= 700000) || __FreeBSD_version <= 602106
+#undef _XOPEN_SOURCE_EXTENDED
+#endif
+#endif
 #else
 #define _GNU_SOURCE
 #if (defined(__APPLE__) || defined(__unix__)) && !defined(__FreeBSD__)
