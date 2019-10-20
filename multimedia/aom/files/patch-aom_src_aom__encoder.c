/usr/bin/ld.bfd: /usr/local/lib/libaom.so: undefined reference to `init_config'

--- aom/src/aom_encoder.c.orig	2019-10-19 19:17:29 UTC
+++ aom/src/aom_encoder.c
@@ -27,7 +27,16 @@
 #include "aom/aom_encoder.h"
 #include "aom/internal/aom_codec_internal.h"
 
-extern void init_config(cfg_options_t *pConfig);
+#if CONFIG_FILEOPTIONS
+// Copied from common/args.c
+extern __attribute__((weak)) void init_config(cfg_options_t *pConfig) {
+  memset(pConfig, 0, sizeof(cfg_options_t));
+  pConfig->super_block_size = 0;  // Dynamic
+  pConfig->max_partition_size = 128;
+  pConfig->min_partition_size = 4;
+  pConfig->disable_trellis_quant = 3;
+}
+#endif
 
 #define SAVE_STATUS(ctx, var) (ctx ? (ctx->err = var) : var)
 
