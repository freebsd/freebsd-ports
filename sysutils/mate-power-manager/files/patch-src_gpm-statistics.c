--- src/gpm-statistics.c.orig	2014-04-06 20:42:27.769248555 +0000
+++ src/gpm-statistics.c	2014-04-06 20:46:41.930233638 +0000
@@ -1796,7 +1796,11 @@
 	g_signal_connect (wakeups, "data-changed", G_CALLBACK (gpm_stats_data_changed_cb), NULL);
 
 	/* coldplug */
+#ifdef HAVE_OLD_UPOWER
 	ret = up_client_enumerate_devices_sync (client, NULL, NULL);
+#else
+	ret = FALSE;
+#endif
 	if (!ret)
 		goto out;
 	devices = up_client_get_devices (client);
