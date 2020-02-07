Allow building before https://github.com/Netflix/vmaf/commit/82a86e040371

aom_dsp/vmaf.c:12:10: fatal error: 'libvmaf/libvmaf.h' file not found
#include <libvmaf/libvmaf.h>
         ^~~~~~~~~~~~~~~~~~~

--- aom_dsp/vmaf.c.orig	2020-02-07 16:59:05 UTC
+++ aom_dsp/vmaf.c
@@ -10,7 +10,11 @@
  */
 
 #include <assert.h>
+#if __has_include(<libvmaf/libvmaf.h>)
 #include <libvmaf/libvmaf.h>
+#else
+#include <libvmaf.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
