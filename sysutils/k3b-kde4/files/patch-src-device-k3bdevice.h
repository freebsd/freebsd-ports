--- src/device/k3bdevice.h.orig	Wed Jun  9 18:36:58 2004
+++ src/device/k3bdevice.h	Sun Jul 11 12:24:22 2004
@@ -677,6 +677,10 @@
 
     class Private;
     Private* d;
+#ifdef __FreeBSD__
+    QString m_passDevice;
+    friend class ScsiCommand;
+#endif
     friend class DeviceManager;
   };
 
