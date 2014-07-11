--- src/utils/dsptools.c.orig	2013-01-14 16:13:45.000000000 +0100
+++ src/utils/dsptools.c	2014-07-11 10:34:30.000000000 +0200
@@ -61,7 +61,7 @@
 #ifdef HAVE_ALLOCA_H
 #include <alloca.h>
 #else
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #endif
