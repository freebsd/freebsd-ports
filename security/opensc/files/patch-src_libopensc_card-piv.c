--- src/libopensc/card-piv.c.orig	2010-12-23 11:56:55.000000000 +0100
+++ src/libopensc/card-piv.c	2010-12-23 11:57:17.000000000 +0100
@@ -28,7 +28,7 @@
 #include <string.h>
 #include <fcntl.h>
 #include <limits.h>
-#ifndef __APPLE__
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
 #endif
 #ifdef ENABLE_OPENSSL
