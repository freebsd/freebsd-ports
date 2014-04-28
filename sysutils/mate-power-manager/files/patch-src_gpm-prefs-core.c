--- src/gpm-prefs-core.c.orig	2014-04-06 20:42:20.438248798 +0000
+++ src/gpm-prefs-core.c	2014-04-06 20:44:21.983436776 +0000
@@ -897,8 +897,13 @@
 		/* are we allowed to shutdown? */
 		egg_console_kit_can_stop (prefs->priv->console, &prefs->priv->can_shutdown, NULL);
 		/* get values from UpClient */
+#ifdef HAVE_OLD_UPOWER
 		prefs->priv->can_suspend = up_client_get_can_suspend (prefs->priv->client);
 		prefs->priv->can_hibernate = up_client_get_can_hibernate (prefs->priv->client);
+#else
+		prefs->priv->can_suspend = FALSE;
+		prefs->priv->can_hibernate = FALSE;
+#endif
 	}
 
 	if (LOGIND_RUNNING()) {
@@ -954,7 +959,11 @@
 	g_object_unref (brightness);
 
 	/* get device list */
+#ifdef HAVE_OLD_UPOWER
 	ret = up_client_enumerate_devices_sync (prefs->priv->client, NULL, &error);
+#else
+	ret = FALSE;
+#endif
 	if (!ret) {
 		egg_warning ("failed to get device list: %s", error->message);
 		g_error_free (error);
