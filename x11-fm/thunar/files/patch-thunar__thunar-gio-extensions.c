--- ./thunar/thunar-gio-extensions.c.orig	2012-12-09 17:28:23.000000000 +0000
+++ ./thunar/thunar-gio-extensions.c	2012-12-10 21:43:55.000000000 +0000
@@ -569,15 +569,34 @@
 thunar_g_app_info_should_show (GAppInfo *info)
 {
 #ifdef HAVE_GIO_UNIX
+#if GLIB_CHECK_VERSION (2, 28, 0)
+  const gchar *filename;
+
+  _thunar_return_val_if_fail (G_IS_APP_INFO (info), FALSE);
+
+  if (g_app_info_should_show (info))
+      return TRUE;
+#else
   _thunar_return_val_if_fail (G_IS_APP_INFO (info), FALSE);
+#endif
 
   if (G_IS_DESKTOP_APP_INFO (info))
+    /* g_desktop_app_info_get_show_in() appears from GLib 2.30 */
+#if GLIB_CHECK_VERSION (2, 28, 0)
+    {
+      filename = g_desktop_app_info_get_filename (G_DESKTOP_APP_INFO (info));
+      if (filename != NULL 
+	&& g_str_has_prefix (filename, g_get_user_data_dir ()))
+          return TRUE;
+    }
+#else
     {
       /* NoDisplay=true files should be visible in the interface,
        * because this key is intent to hide mime-helpers from the
        * application menu. Hidden=true is never returned by GIO. */
       return g_desktop_app_info_get_show_in (G_DESKTOP_APP_INFO (info), NULL);
     }
+#endif
 
   return TRUE;
 #else
