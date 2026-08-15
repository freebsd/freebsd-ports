--- examples/simple/anariTutorial.c.orig	2026-07-19 23:31:40 UTC
+++ examples/simple/anariTutorial.c
@@ -13,7 +13,9 @@
 #ifdef _WIN32
 #include <malloc.h>
 #else
+#  ifndef __FreeBSD__
 #include <alloca.h>
+#  endif
 #endif
 #include <errno.h>
 #include <stdint.h>
