--- Telegram/SourceFiles/platform/linux/linux_libs.h.orig	2019-09-27 17:04:25 UTC
+++ Telegram/SourceFiles/platform/linux/linux_libs.h
@@ -13,11 +13,13 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 
 extern "C" {
 #undef signals
+#ifdef HAVE_APPINDICATOR
 #ifdef TDESKTOP_USE_AYATANA_INDICATORS
 #include <libayatana-appindicator/app-indicator.h>
 #else
 #include <libappindicator/app-indicator.h>
 #endif
+#endif
 #include <gtk/gtk.h>
 #include <gdk/gdk.h>
 #define signals public
@@ -278,6 +280,7 @@ inline gulong g_signal_connect_swapped_helper(gpointer
 typedef void (*f_g_signal_handler_disconnect)(gpointer instance, gulong handler_id);
 extern f_g_signal_handler_disconnect g_signal_handler_disconnect;
 
+#ifdef HAVE_APPINDICATOR
 typedef AppIndicator* (*f_app_indicator_new)(const gchar *id, const gchar *icon_name, AppIndicatorCategory category);
 extern f_app_indicator_new app_indicator_new;
 
@@ -289,6 +292,7 @@ extern f_app_indicator_set_menu app_indicator_set_menu
 
 typedef void (*f_app_indicator_set_icon_full)(AppIndicator *self, const gchar *icon_name, const gchar *icon_desc);
 extern f_app_indicator_set_icon_full app_indicator_set_icon_full;
+#endif
 
 typedef gboolean (*f_gdk_init_check)(gint *argc, gchar ***argv);
 extern f_gdk_init_check gdk_init_check;
