--- src/gpm-button.c.orig	2009-04-19 02:17:58.000000000 -0400
+++ src/gpm-button.c	2009-04-19 02:20:39.000000000 -0400
@@ -494,6 +494,25 @@ hal_daemon_stop_cb (HalGManager *hal_man
 	}
 }
 
+/*
+ * hal_daemon_new_device_cb
+ **/
+static void
+hal_daemon_new_device_cb (HalGManager *hal_manager, const gchar *udi, GpmButton *button)
+{
+	gboolean is_button;
+	HalGDevice *device;
+
+	device = hal_gdevice_new ();
+	hal_gdevice_set_udi (device, udi);
+	hal_gdevice_query_capability (device, "button", &is_button, NULL);
+	if (is_button == TRUE) {
+		egg_debug ("Watching %s", udi);
+		watch_add_button (button, udi);
+	}
+	g_object_unref (device);
+}
+
 /**
  * gpm_button_init:
  * @button: This class instance
@@ -543,6 +562,8 @@ gpm_button_init (GpmButton *button)
 			  G_CALLBACK (hal_daemon_start_cb), button);
 	g_signal_connect (button->priv->hal_manager, "daemon-stop",
 			  G_CALLBACK (hal_daemon_stop_cb), button);
+	g_signal_connect (button->priv->hal_manager, "device-added",
+			  G_CALLBACK (hal_daemon_new_device_cb), button);
 
 	button->priv->hal_devicestore = hal_gdevicestore_new ();
 
