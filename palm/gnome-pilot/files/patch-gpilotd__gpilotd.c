--- gpilotd/gpilotd.c.orig	2008-02-26 19:02:35.000000000 -0500
+++ gpilotd/gpilotd.c	2008-07-04 19:27:40.000000000 -0400
@@ -27,6 +27,8 @@
 #include "config.h"
 #endif
 
+#define freebsd
+
 /* for crypt () */
 #ifdef USE_XOPEN_SOURCE
 #ifndef _XOPEN_SOURCE
@@ -1279,6 +1281,47 @@ gpilotd_hal_init (void)
 #endif /* WITH_HAL */
 #ifdef WITH_USB_VISOR
 
+#ifdef freebsd
+static gboolean
+visor_devices_timeout (gpointer data)
+{
+	GPilotContext *context = data;
+	GPilotDevice *device;
+	GList *l;
+	int i;
+	gboolean visor_exists = FALSE, visor_net = TRUE;
+
+	g_assert (context != NULL);
+
+	if (context->paused)
+		return FALSE;
+
+	l = context->devices;
+	while (l) {
+		struct stat dummy;
+
+		device = l->data;
+
+		/* Make sure usb device exists */
+		if (stat(device->port, &dummy) == 0) {
+			if (device->type == PILOT_DEVICE_USB_VISOR) {
+				if (!visor_net)
+					device->type = PILOT_DEVICE_SERIAL;
+
+				/* just try to synch.  Until I can talk to
+				 * the kernel guys this is the best way to
+				 * go. */
+				sync_device (device, context);
+				if (!visor_net)
+					device->type = PILOT_DEVICE_USB_VISOR;
+			}
+		}
+		l = l->next;
+	}
+
+	return TRUE;
+}
+#else
 static gboolean 
 visor_devices_timeout (gpointer data) 
 {
@@ -1448,6 +1491,7 @@ visor_devices_timeout (gpointer data) 
 	return TRUE;
 }
 
+#endif
 #endif /* WITH_USB_VISOR */
 
 
@@ -1486,7 +1530,7 @@ monitor_channel (GPilotDevice *dev, GPil
 			dev->device_exists = FALSE;
 		} else {
 #ifdef WITH_USB_VISOR
-#if defined(linux) || (defined(sun) && defined(__SVR4))
+#if defined(linux) || defined(freebsd) || (defined(sun) && defined(__SVR4))
 			/* We want to watch for a new recognised USB device
 			 * once per context. */
 			if (visor_timeout_id == -1) {
