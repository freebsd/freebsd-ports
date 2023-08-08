--- src/utils/dsptools.c.orig	2023-07-27 14:00:34 UTC
+++ src/utils/dsptools.c
@@ -62,7 +62,7 @@
 #ifdef HAVE_ALLOCA_H
 #include <alloca.h>
 #else
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <malloc.h>
 #endif
 #endif
