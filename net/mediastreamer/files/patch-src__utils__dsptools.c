--- src/utils/dsptools.c.orig	2022-06-10 12:50:07 UTC
+++ src/utils/dsptools.c
@@ -61,7 +61,7 @@
 #ifdef HAVE_ALLOCA_H
 #include <alloca.h>
 #else
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <malloc.h>
 #endif
 #endif
