Allow building before https://github.com/Netflix/vmaf/commit/82a86e040371

aom_dsp/vmaf.c:12:10: fatal error: 'libvmaf/libvmaf.h' file not found
#include <libvmaf/libvmaf.h>
         ^~~~~~~~~~~~~~~~~~~

--- aom_dsp/vmaf.c.orig	2020-01-10 22:53:28 UTC
+++ aom_dsp/vmaf.c
@@ -9,7 +9,11 @@
  * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
  */
 #include <assert.h>
+#if __has_include(<libvmaf/libvmaf.h>)
 #include <libvmaf/libvmaf.h>
+#else
+#include <libvmaf.h>
+#endif
 #include <stdlib.h>
 
 #include "aom_dsp/vmaf.h"
