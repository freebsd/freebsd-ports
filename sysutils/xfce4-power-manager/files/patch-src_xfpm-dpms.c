--- src/xfpm-dpms.c.orig	2020-01-26 23:15:39 UTC
+++ src/xfpm-dpms.c
@@ -119,13 +119,13 @@ xfpm_dpms_get_enabled (XfpmDpms *dpms, gboolean *dpms_
 static void
 xfpm_dpms_get_sleep_mode (XfpmDpms *dpms, gboolean *ret_standby_mode)
 {
-  gchar *sleep_mode;
+  gchar *sleep_mode = NULL;
 
   g_object_get (G_OBJECT (dpms->priv->conf),
                 DPMS_SLEEP_MODE, &sleep_mode,
                 NULL);
 
-  if ( !g_strcmp0 (sleep_mode, "Standby"))
+  if ( sleep_mode != NULL && !g_strcmp0 (sleep_mode, "Standby"))
     *ret_standby_mode = TRUE;
   else
     *ret_standby_mode = FALSE;
