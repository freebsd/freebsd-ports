--- ./src/plugins.h.orig	2012-06-25 19:44:08.000000000 +0200
+++ ./src/plugins.h	2012-06-25 19:46:11.000000000 +0200
@@ -12,7 +12,7 @@
 #include <string.h>
 #include <fcntl.h>
 #include <stdlib.h>
-
+#include "../libweed/weed-effects.h"
 
 // generic plugins
 
@@ -36,7 +36,6 @@
 GList *plugin_request_by_space (const gchar *plugin_type, const gchar *plugin_name, const gchar *request);
 GList *plugin_request_common (const gchar *plugin_type, const gchar *plugin_name, const gchar *request, const gchar *delim, gboolean allow_blanks);
 
-typedef weed_plant_t *(*weed_bootstrap_f) (weed_default_getter_f *value, int num_versions, int *plugin_versions);
 
 /// video playback plugins
 typedef gboolean (*plugin_keyfunc) (gboolean down, guint16 unicode, guint16 keymod);
