--- libgupnp/gupnp-device.h.orig	2013-12-01 19:32:50.000000000 +0800
+++ libgupnp/gupnp-device.h	2014-05-09 01:24:34.890234566 +0800
@@ -51,7 +51,9 @@
                  GUPnPDeviceClass))
 
 typedef struct _GUPnPDevicePrivate GUPnPDevicePrivate;
+#if !defined(GUPnPDevice)
 typedef struct _GUPnPDevice GUPnPDevice;
+#endif
 typedef struct _GUPnPDeviceClass GUPnPDeviceClass;
 
 /**
