--- src/xfpm-dpms.c.orig	2024-11-21 06:26:21 UTC
+++ src/xfpm-dpms.c
@@ -93,7 +93,7 @@ refresh (XfpmDpms *dpms)
   gboolean enabled;
   guint off_timeout;
   guint sleep_timeout;
-  gchar *sleep_mode;
+  gchar *sleep_mode = NULL;
 
   if (priv->inhibited)
   {
@@ -115,7 +115,7 @@ refresh (XfpmDpms *dpms)
   g_object_get (G_OBJECT (priv->conf), DPMS_SLEEP_MODE, &sleep_mode, NULL);
 
   XFPM_DPMS_GET_CLASS (dpms)->set_enabled (dpms, TRUE);
-  XFPM_DPMS_GET_CLASS (dpms)->set_timeouts (dpms, g_strcmp0 (sleep_mode, "Standby") == 0,
+  XFPM_DPMS_GET_CLASS (dpms)->set_timeouts (dpms, sleep_mode != NULL && g_strcmp0 (sleep_mode, "Standby") == 0,
                                             sleep_timeout * 60, off_timeout * 60);
 
   g_free (sleep_mode);
