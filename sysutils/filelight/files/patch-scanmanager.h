--- src/scanmanager.h.orig	Fri Aug 13 23:50:09 2004
+++ src/scanmanager.h	Sat Aug 14 00:32:26 2004
@@ -65,6 +65,8 @@
     static bool readMounts();
 private:
     static QStringList localMounts, remoteMounts;
+
+    friend class ScanThread;
 };
 
 
