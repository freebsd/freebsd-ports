--- examples/simple/anariTutorialDebug.c.orig	2026-07-19 23:31:40 UTC
+++ examples/simple/anariTutorialDebug.c
@@ -4,7 +4,9 @@
 #ifdef _WIN32
 #include <malloc.h>
 #else
+#  ifndef __FreeBSD__
 #include <alloca.h>
+#  endif
 #endif
 #include <errno.h>
 #include <stdint.h>
