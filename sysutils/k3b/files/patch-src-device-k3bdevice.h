--- src/device/k3bdevice.h.orig	Thu Jul 29 12:07:16 2004
+++ src/device/k3bdevice.h	Sun Aug 22 15:28:36 2004
@@ -677,6 +677,10 @@
 
     class Private;
     Private* d;
+#ifdef __FreeBSD__
+    QString m_passDevice;
+    friend class ScsiCommand;
+#endif
     friend class DeviceManager;
   };
 
