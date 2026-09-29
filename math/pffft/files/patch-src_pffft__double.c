-- Upstreamed: https://github.com/marton78/pffft/pull/105

--- src/pffft_double.c.orig	2026-09-29 15:09:52 UTC
+++ src/pffft_double.c
@@ -75,6 +75,8 @@
 #  include <malloc.h>
 #elif defined(__MINGW32__) || defined(__MINGW64__)
 #  include <malloc.h>
+#elif defined(__FreeBSD__)
+#  include <malloc.h>
 #else
 #  include <alloca.h>
 #endif
