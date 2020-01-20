Allow building before https://github.com/Netflix/vmaf/commit/82a86e040371

aom_dsp/vmaf.c:12:10: fatal error: 'libvmaf/libvmaf.h' file not found
#include <libvmaf/libvmaf.h>
         ^~~~~~~~~~~~~~~~~~~

Don't use CLI symbols in shared library

  /usr/lib/libaom.so: undefined reference to `fatal'

--- aom_dsp/vmaf.c.orig	2020-01-17 20:13:03 UTC
+++ aom_dsp/vmaf.c
@@ -9,13 +9,17 @@
  * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
  */
 #include <assert.h>
+#if __has_include(<libvmaf/libvmaf.h>)
 #include <libvmaf/libvmaf.h>
+#else
+#include <libvmaf.h>
+#endif
+#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #include "aom_dsp/vmaf.h"
 #include "aom_ports/system_state.h"
-#include "common/tools_common.h"
 
 typedef struct FrameData {
   const YV12_BUFFER_CONFIG *source;
@@ -82,7 +86,10 @@ void aom_calc_vmaf(const char *model_path, const YV12_
 
   aom_clear_system_state();
   *vmaf = vmaf_score;
-  if (ret) fatal("Failed to compute VMAF scores.");
+  if (ret) {
+    fprintf(stderr, "Failed to compute VMAF scores.\n");
+    exit(EXIT_FAILURE);
+  }
 }
 
 void aom_calc_vmaf_multi_frame(
@@ -102,7 +109,10 @@ void aom_calc_vmaf_multi_frame(
       /*do_ms_ssim=*/0, /*pool_method=*/NULL, /*n_thread=*/0,
       /*n_subsample=*/1, /*enable_conf_interval=*/0);
   FILE *vmaf_log = fopen("vmaf_scores.xml", "r");
-  if (vmaf_log == NULL || ret) fatal("Failed to compute VMAF scores.");
+  if (vmaf_log == NULL || ret) {
+    fprintf(stderr, "Failed to compute VMAF scores.\n");
+    exit(EXIT_FAILURE);
+  }
 
   int frame_index = 0;
   char buf[512];
@@ -114,7 +124,8 @@ void aom_calc_vmaf_multi_frame(
         *p2 = '\0';
         const double score = atof(&p[6]);
         if (score < 0.0 || score > 100.0) {
-          fatal("Failed to compute VMAF scores.");
+          fprintf(stderr, "Failed to compute VMAF scores.\n");
+          exit(EXIT_FAILURE);
         }
         vmaf[frame_index++] = score;
       }
