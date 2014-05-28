--- libgupnp/gupnp-device.h.orig	2013-12-01 19:32:50.000000000 +0800
+++ libgupnp/gupnp-device.h	2014-05-28 13:01:03.041207000 +0800
@@ -51,7 +51,10 @@
                  GUPnPDeviceClass))
 
 typedef struct _GUPnPDevicePrivate GUPnPDevicePrivate;
+#if !defined(__typedef_GUPnPDevice__)
+#define __typedef_GUPnPDevice__
 typedef struct _GUPnPDevice GUPnPDevice;
+#endif
 typedef struct _GUPnPDeviceClass GUPnPDeviceClass;
 
 /**
