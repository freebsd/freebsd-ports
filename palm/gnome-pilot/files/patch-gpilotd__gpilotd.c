--- gpilotd/gpilotd.c.orig	Thu Sep  2 11:43:47 2004
+++ gpilotd/gpilotd.c	Sun Apr 24 15:56:14 2005
@@ -27,6 +27,8 @@
 #include "config.h"
 #endif
 
+#define freebsd
+
 /* for crypt () */
 #ifdef USE_XOPEN_SOURCE
 #ifndef _XOPEN_SOURCE
@@ -903,7 +905,7 @@
 	}
 	
 	fclose (f);
-	
+
 	if (visor_exists) {
 		l = context->devices;
 		while (l) {
@@ -928,6 +930,49 @@
 }
 
 #endif
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
+
+	}
+
+	return TRUE;
+}
+
+#endif
 #endif
 
 void monitor_channel (GPilotDevice *dev,GPilotContext *context) 
@@ -959,16 +1004,12 @@
 #endif /* WITH_NETWORK */
 	} if (dev->type == PILOT_DEVICE_USB_VISOR) {
 #ifdef WITH_USB_VISOR
-#ifdef linux
 		/* We want to watch the /proc/bus/usb/devices file once 
 		 * per context, and then check all devices each time it is
 		 * woken up. */
 		if (visor_timeout_id == -1) {
 			visor_timeout_id = g_timeout_add (2000, visor_devices_timeout, context);
 		}
-#else /* linux*/
-		g_assert_not_reached ();
-#endif /* linux */
 #endif /* WITH_USB_VISOR */
 		dev->device_exists = FALSE;
 	}
