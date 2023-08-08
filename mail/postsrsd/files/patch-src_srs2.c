--- src/srs2.c.orig	2023-07-15 18:53:41 UTC
+++ src/srs2.c
@@ -21,6 +21,7 @@
 #include <postsrsd_build_config.h>
 #include <stdarg.h>
 #include <string.h> /* memcpy, strcpy, memset */
+#include <strings.h>
 #ifdef HAVE_ALLOCA_H
 #    include <alloca.h>
 #endif
