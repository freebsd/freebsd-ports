--- libmpeg2/idct_alpha.c.orig	Wed May 14 13:19:19 2003
+++ libmpeg2/idct_alpha.c	Wed May 14 13:19:32 2003
@@ -24,6 +24,14 @@
 
 #include "config.h"
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+typedef __int32_t int_fast32_t;
+#endif
+
 #ifdef ARCH_ALPHA
 
 #include <stdlib.h>
