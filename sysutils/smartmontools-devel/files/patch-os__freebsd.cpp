--- os_freebsd.cpp.orig	2006-09-17 05:17:53.000000000 +0200
+++ os_freebsd.cpp	2007-10-21 18:09:02.000000000 +0200
@@ -873,6 +873,7 @@
 static const char * fbsd_dev_prefix = "/dev/";
 static const char * fbsd_dev_ata_disk_prefix = "ad";
 static const char * fbsd_dev_scsi_disk_plus = "da";
+static const char * fbsd_dev_scsi_pass = "pass";
 static const char * fbsd_dev_scsi_tape1 = "sa";
 static const char * fbsd_dev_scsi_tape2 = "nsa";
 static const char * fbsd_dev_scsi_tape3 = "esa";
@@ -908,6 +909,11 @@
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
@@ -1008,7 +1014,7 @@
   // to first list. Turn on NOCHECK for second call. This results in no
   // error if no more matches found, however it does append the actual
   // pattern to the list of paths....
-  if ((retglob=glob(pattern1, GLOB_ERR, NULL, &globbuf)) ||
+  if ((retglob=glob(pattern1, GLOB_ERR|GLOB_NOCHECK, NULL, &globbuf)) ||
       (retglob=glob(pattern2, GLOB_ERR|GLOB_APPEND|GLOB_NOCHECK,NULL,&globbuf))) {
      int retval = -1;
     // glob failed
