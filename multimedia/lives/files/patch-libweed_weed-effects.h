--- libweed/weed-effects.h.orig	2015-04-17 23:38:34 UTC
+++ libweed/weed-effects.h
@@ -126,7 +126,9 @@ extern "C"
 #define WEED_ERROR_PLUGIN_INVALID 64
 
 /* host bootstrap function */
+#ifndef PLUGIN_ENCODERS
 typedef weed_plant_t *(*weed_bootstrap_f)(weed_default_getter_f *value, int num_versions, int *plugin_versions);
+#endif
 
 /* plugin only functions */
 typedef weed_plant_t *(*weed_setup_f)(weed_bootstrap_f weed_boot);
