--- lineak/cdromctrl.cpp.orig	Thu Oct 28 17:04:06 2004
+++ lineak/cdromctrl.cpp	Sat Jan 15 11:28:04 2005
@@ -26,6 +26,12 @@
 # define CDROMEJECT CDIOCEJECT /*_IO('c', 107)*/
 # define CDROMCLOSETRAY CDIOCCLOSE
 #else
+#  include <sys/mount.h>
+
+#  include <scsi/scsi.h>
+#  include <scsi/sg.h>
+#  include <scsi/scsi_ioctl.h>
+
 #  include <linux/version.h>
 #  if LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,70)
      typedef unsigned char u8;
@@ -37,16 +43,11 @@
 
 #include <sys/stat.h>
 #include <sys/types.h>
-#include <sys/mount.h>
 
 #include <stdio.h>
 #include <errno.h>
 #include <unistd.h>
 
-#include <scsi/scsi.h>
-#include <scsi/sg.h>
-#include <scsi/scsi_ioctl.h>
-
 }
 #include <iostream>
 
@@ -141,6 +142,9 @@
 }
 /** OPen the tray for a scsi device */
 void cdromCtrl::openTrayScsi(){
+  #if defined (__FreeBSD__)
+  cdromCtrl::openTray();
+  #else
    /* do we have a CD-ROM device configured?  (extra check, not really nescessary) */
    if ( cdromdev != snull && initialized) {
         lineak_core_functions::msg("... ejecting the SCSI CD-ROM tray");
@@ -196,6 +200,7 @@
         status = ioctl(fp, BLKRRPART);
  //       return (status == 0);
    }
+#endif
 }
 /** Set or disable the auto-eject mode. If auto-eject mode is enabled, the cdrom device
     will eject when we issue a close(fp); */
