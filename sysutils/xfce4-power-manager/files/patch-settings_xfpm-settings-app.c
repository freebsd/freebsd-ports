--- settings/xfpm-settings-app.c.orig	2017-11-23 23:52:06 UTC
+++ settings/xfpm-settings-app.c
@@ -195,7 +195,6 @@ xfpm_settings_app_launch (GApplication *app)
         if (start_xfpm_if_not_running == GTK_RESPONSE_YES)
         {
             GAppInfo *app_info;
-            GError   *error = NULL;
 
             app_info = g_app_info_create_from_commandline ("xfce4-power-manager", "Xfce4 Power Manager",
                                                            G_APP_INFO_CREATE_SUPPORTS_STARTUP_NOTIFICATION, NULL);
