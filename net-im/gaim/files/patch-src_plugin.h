--- src/plugin.h.orig	Fri Feb 27 15:18:51 2004
+++ src/plugin.h	Fri Feb 27 15:19:15 2004
@@ -117,7 +117,7 @@
 /**
  * Handles the initialization of modules.
  */
-#if !defined(GAIM_PLUGINS) || defined(STATIC)
+#if !defined(GAIM_PLUGINS) || defined(GAIM_STATIC_PRPL)
 # define GAIM_INIT_PLUGIN(pluginname, initfunc, plugininfo) \
 	gboolean gaim_init_##pluginname##_plugin(void) { \
 		GaimPlugin *plugin = gaim_plugin_new(TRUE, NULL); \
@@ -125,7 +125,7 @@
 		initfunc((plugin)); \
 		return gaim_plugin_register(plugin); \
 	}
-#else /* GAIM_PLUGINS  && !STATIC */
+#else /* GAIM_PLUGINS  && !GAIM_STATIC_PRPL */
 # define GAIM_INIT_PLUGIN(pluginname, initfunc, plugininfo) \
 	G_MODULE_EXPORT gboolean gaim_init_plugin(GaimPlugin *plugin) { \
 		plugin->info = &(plugininfo); \
