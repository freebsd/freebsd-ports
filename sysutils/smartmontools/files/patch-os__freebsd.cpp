
$FreeBSD$

--- os_freebsd.cpp.orig
+++ os_freebsd.cpp
@@ -272,7 +272,6 @@
 }
 
 int highpoint_command_interface(__unused int fd, __unused smart_command_set command, __unused int select, __unused char *data) {
-{
   return -1;
 }
 
@@ -341,6 +340,15 @@
     request.count=512;
     copydata=1;
     break;
+  case WRITE_LOG:
+    memcpy(buff, data, 512);
+    request.u.ata.feature=ATA_SMART_WRITE_LOG_SECTOR;
+    request.u.ata.lba=select|(0xc24f<<8);
+    request.u.ata.count=1;
+    request.flags=ATA_CMD_WRITE;
+    request.data=(char *)buff;
+    request.count=512;
+    break;
   case IDENTIFY:
     request.u.ata.command=ATA_IDENTIFY_DEVICE;
     request.flags=ATA_CMD_READ;
@@ -525,7 +533,7 @@
     return -1;
   }
 
-  if ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
+  if (((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) && ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_SCSI_STATUS_ERROR)) {
  #if __FreeBSD_version > 500000
     cam_error_print(cam_dev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
  #endif
@@ -924,6 +932,7 @@
 static const char * fbsd_dev_prefix = "/dev/";
 static const char * fbsd_dev_ata_disk_prefix = "ad";
 static const char * fbsd_dev_scsi_disk_plus = "da";
+static const char * fbsd_dev_scsi_pass = "pass";
 static const char * fbsd_dev_scsi_tape1 = "sa";
 static const char * fbsd_dev_scsi_tape2 = "nsa";
 static const char * fbsd_dev_scsi_tape3 = "esa";
@@ -960,6 +969,11 @@
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
