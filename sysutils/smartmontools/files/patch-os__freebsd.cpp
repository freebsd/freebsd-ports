--- os_freebsd.cpp.orig	2008-03-04 23:09:47.000000000 +0100
+++ os_freebsd.cpp	2008-03-14 13:52:37.000000000 +0100
@@ -272,7 +272,6 @@
 }
 
 int highpoint_command_interface(__unused int fd, __unused smart_command_set command, __unused int select, __unused char *data) {
-{
   return -1;
 }
 
@@ -924,6 +923,7 @@
 static const char * fbsd_dev_prefix = "/dev/";
 static const char * fbsd_dev_ata_disk_prefix = "ad";
 static const char * fbsd_dev_scsi_disk_plus = "da";
+static const char * fbsd_dev_scsi_pass = "pass";
 static const char * fbsd_dev_scsi_tape1 = "sa";
 static const char * fbsd_dev_scsi_tape2 = "nsa";
 static const char * fbsd_dev_scsi_tape3 = "esa";
@@ -960,6 +960,11 @@
     return CONTROLLER_ATA;
   }
   
+  // form /dev/pass* or pass*
+  if (!strncmp(fbsd_dev_scsi_pass, dev_name,
+               strlen(fbsd_dev_scsi_pass)))
+    goto handlescsi;
+
   // form /dev/da* or da*
   if (!strncmp(fbsd_dev_scsi_disk_plus, dev_name,
                strlen(fbsd_dev_scsi_disk_plus)))
