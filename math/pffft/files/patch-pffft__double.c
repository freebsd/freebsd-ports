--- pffft_double.c.orig	2022-01-30 17:29:25 UTC
+++ pffft_double.c
@@ -75,6 +75,8 @@
 #  include <malloc.h>
 #elif defined(__MINGW32__) || defined(__MINGW64__)
 #  include <malloc.h>
+#elif defined(__FreeBSD__)
+#  include <stdlib.h>
 #else
 #  include <alloca.h>
 #endif
