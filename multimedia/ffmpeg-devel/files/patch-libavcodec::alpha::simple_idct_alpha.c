--- libavcodec/alpha/simple_idct_alpha.c.bak	Fri Dec 27 12:35:23 2002
+++ libavcodec/alpha/simple_idct_alpha.c	Tue May 13 21:21:42 2003
@@ -24,8 +24,16 @@
  *                     and Falk Hueffner <falk@debian.org>
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "asm.h"
 #include "../dsputil.h"
+
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+typedef __int32_t int_fast32_t;
+#endif
 
 extern void (*put_pixels_clamped_axp_p)(const DCTELEM *block, uint8_t *pixels,
                                         int line_size);
