--- src/post/deinterlace/deinterlace.h.orig	Sun Aug 10 01:05:01 2003
+++ src/post/deinterlace/deinterlace.h	Sun Aug 10 01:18:58 2003
@@ -22,7 +22,11 @@
 #if defined (__SVR4) && defined (__sun)
 # include <sys/int_types.h>
 #else
-# include <stdint.h>
+# if defined(HAVE_STDINT_H)
+#  include <stdint.h>
+# else
+#  include <inttypes.h>
+# endif
 #endif
 
 #ifdef __cplusplus
