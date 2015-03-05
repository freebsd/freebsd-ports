--- panel-plugins/power-manager-plugin/xfce/xfce-power-manager-plugin.c.orig	2014-08-20 20:18:43 UTC
+++ panel-plugins/power-manager-plugin/xfce/xfce-power-manager-plugin.c
@@ -33,6 +33,7 @@
 #ifdef XFCE_PLUGIN
 #include <libxfce4panel/libxfce4panel.h>
 #include <libxfce4panel/xfce-panel-plugin.h>
+#include <libxfce4util/libxfce4util.h>
 #endif
 
 #include "../power-manager-button.h"
@@ -84,6 +85,8 @@ power_manager_plugin_construct (XfcePane
 {
     PowerManagerPlugin *power_manager_plugin;
 
+    xfce_textdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR, "UTF-8");
+
     /* create the plugin */
     power_manager_plugin = power_manager_plugin_new (plugin);
 
