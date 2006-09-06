--- gpilotd/gpilotd.c.orig	Tue Sep  5 03:16:41 2006
+++ gpilotd/gpilotd.c	Wed Sep  6 17:04:43 2006
@@ -27,6 +27,8 @@
 #include "config.h"
 #endif
 
+#define freebsd
+
 /* for crypt () */
 #ifdef USE_XOPEN_SOURCE
 #ifndef _XOPEN_SOURCE
@@ -1386,6 +1388,49 @@ visor_devices_timeout (gpointer data) 
 }
 
 #endif /* WITH_USB_VISOR */
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
+#endif /* freebsd */
 #endif /* linux */
 
 
@@ -1423,16 +1468,12 @@ monitor_channel (GPilotDevice *dev, GPil
 			dev->device_exists = FALSE;
 		} else {
 #ifdef WITH_USB_VISOR
-#ifdef linux
 			/* We want to watch for a new recognised USB device
 			 * once per context. */
 			if (visor_timeout_id == -1) {
 				visor_timeout_id = g_timeout_add (2000,
 				    visor_devices_timeout, context);
 			}
-#else /* linux */
-			g_assert_not_reached ();
-#endif /* linux */
 #endif /* WITH_USB_VISOR */
 		}
 	}
