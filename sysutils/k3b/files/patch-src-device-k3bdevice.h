--- src/device/k3bdevice.h.orig	Sun Nov 28 13:27:24 2004
+++ src/device/k3bdevice.h	Sun Jan  2 09:30:08 2005
@@ -690,6 +690,10 @@
 
     class Private;
     Private* d;
+#ifdef __FreeBSD__
+    QString m_passDevice;
+    friend class ScsiCommand;
+#endif
     friend class DeviceManager;
   };
 
