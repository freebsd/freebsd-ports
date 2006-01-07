--- src/kcddrive.cpp.orig	Sun Dec 18 18:36:56 2005
+++ src/kcddrive.cpp	Fri Jan  6 18:01:33 2006
@@ -21,6 +21,7 @@
 
 #include "kcddrive.h"
 #include <kprocess.h>
+#include <sys/param.h>
 #include <sys/mount.h>
 kCDDrive::kCDDrive() {
     canReadDVD=false;
@@ -55,7 +56,7 @@
 	if (process->isRunning()) process->wait(-1);
 	delete process;
 */
-	umount(device.latin1());
+	unmount(device.latin1(),0);
 	dev->eject();
 	}
    }
@@ -99,6 +100,7 @@
 void kCDDrives::scanDrives() {
     int i;
     drives.clear();
+    dm->clear();
     dm->scanBus();
     dm->scanFstab();
 
@@ -128,4 +130,4 @@
 /** No descriptions */
 kCDDrive * kCDDrives::getDrive(int num) {
     return (kCDDrive *)drives.at(num);
-}
\ No newline at end of file
+}
