--- src/device/k3bdevice.h.orig	Fri Jan 30 11:28:15 2004
+++ src/device/k3bdevice.h	Fri Feb 13 21:03:38 2004
@@ -654,6 +654,10 @@
 
     class Private;
     Private* d;
+#ifdef __FreeBSD__
+    QString m_passDevice;
+    friend class ScsiCommand;
+#endif
     friend class DeviceManager;
   };
 
