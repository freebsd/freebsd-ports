--- src/device/k3bdevicemanager.h.orig	Wed Jan 21 11:20:11 2004
+++ src/device/k3bdevicemanager.h	Tue May 11 22:57:03 2004
@@ -112,6 +112,10 @@
 
       class Private;
       Private* d;
+#ifdef __FreeBSD__
+      void bsd_scan_devices();
+      CdDevice* addDevice( CdDevice* );
+#endif
     };
 }
 
