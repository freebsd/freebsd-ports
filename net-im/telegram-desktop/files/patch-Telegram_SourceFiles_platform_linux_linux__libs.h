--- Telegram/SourceFiles/platform/linux/linux_libs.h.orig	2018-12-24 08:16:05 UTC
+++ Telegram/SourceFiles/platform/linux/linux_libs.h
@@ -10,18 +10,20 @@ https://github.com/telegramdesktop/tdesk
 #ifndef TDESKTOP_DISABLE_GTK_INTEGRATION
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
 } // extern "C"
 
 #ifndef TDESKTOP_DISABLE_UNITY_INTEGRATION
-#include <unity/unity/unity.h>
+typedef void UnityLauncherEntry;
 #endif // !TDESKTOP_DISABLE_UNITY_INTEGRATION
 #endif // !TDESKTOP_DISABLE_GTK_INTEGRATION
 
@@ -278,6 +280,7 @@ inline gulong g_signal_connect_swapped_h
 typedef void (*f_g_signal_handler_disconnect)(gpointer instance, gulong handler_id);
 extern f_g_signal_handler_disconnect g_signal_handler_disconnect;
 
+#ifdef HAVE_APPINDICATOR
 typedef AppIndicator* (*f_app_indicator_new)(const gchar *id, const gchar *icon_name, AppIndicatorCategory category);
 extern f_app_indicator_new app_indicator_new;
 
@@ -289,6 +292,7 @@ extern f_app_indicator_set_menu app_indi
 
 typedef void (*f_app_indicator_set_icon_full)(AppIndicator *self, const gchar *icon_name, const gchar *icon_desc);
 extern f_app_indicator_set_icon_full app_indicator_set_icon_full;
+#endif
 
 typedef gboolean (*f_gdk_init_check)(gint *argc, gchar ***argv);
 extern f_gdk_init_check gdk_init_check;
