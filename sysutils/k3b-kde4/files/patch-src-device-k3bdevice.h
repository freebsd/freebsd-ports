--- src/device/k3bdevice.h.orig	Sun Mar 14 17:35:20 2004
+++ src/device/k3bdevice.h	Tue May 11 22:57:03 2004
@@ -661,6 +661,10 @@
 
     class Private;
     Private* d;
+#ifdef __FreeBSD__
+    QString m_passDevice;
+    friend class ScsiCommand;
+#endif
     friend class DeviceManager;
   };
 
