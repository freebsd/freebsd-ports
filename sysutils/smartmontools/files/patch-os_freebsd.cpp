--- os_freebsd.cpp.orig	2013-07-05 12:40:38.000000000 +0200
+++ os_freebsd.cpp	2014-03-03 19:16:11.000000000 +0100
@@ -75,7 +75,7 @@
 #define PATHINQ_SETTINGS_SIZE   128
 #endif
 
-const char *os_XXXX_c_cvsid="$Id: os_freebsd.cpp 3824 2013-07-05 10:40:38Z samm2 $" \
+const char *os_XXXX_c_cvsid="$Id: os_freebsd.cpp 3874 2014-02-18 00:47:23Z samm2 $" \
 ATACMDS_H_CVSID CCISS_H_CVSID CONFIG_H_CVSID INT64_H_CVSID OS_FREEBSD_H_CVSID SCSICMDS_H_CVSID UTILITY_H_CVSID;
 
 #define NO_RETURN 0
@@ -135,9 +135,9 @@
 : virtual public /*implements*/ smart_device
 {
 public:
-  explicit freebsd_smart_device(const char * mode)
+  explicit freebsd_smart_device()
     : smart_device(never_called),
-      m_fd(-1), m_mode(mode) { }
+      m_fd(-1) { }
 
   virtual ~freebsd_smart_device() throw();
 
@@ -157,7 +157,6 @@
 
 private:
   int m_fd; ///< filedesc, -1 if not open.
-  const char * m_mode; ///< Mode string for deviceopen().
 };
 
 #ifdef __GLIBC__
@@ -249,7 +248,7 @@
 
 freebsd_ata_device::freebsd_ata_device(smart_interface * intf, const char * dev_name, const char * req_type)
 : smart_device(intf, dev_name, "ata", req_type),
-  freebsd_smart_device("ATA")
+  freebsd_smart_device()
 {
 }
 
@@ -445,7 +444,8 @@
   }
 
   if ((ccb.ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
-    cam_error_print(m_camdev, &ccb, CAM_ESF_ALL, CAM_EPF_ALL, stderr);
+    if(scsi_debugmode > 0)
+      cam_error_print(m_camdev, &ccb, CAM_ESF_ALL, CAM_EPF_ALL, stderr);
     set_err(EIO);
     return -1;
   }
@@ -489,10 +489,7 @@
 freebsd_escalade_device::freebsd_escalade_device(smart_interface * intf, const char * dev_name,
     int escalade_type, int disknum)
 : smart_device(intf, dev_name, "3ware", "3ware"),
-  freebsd_smart_device(
-    escalade_type==CONTROLLER_3WARE_9000_CHAR ? "ATA_3WARE_9000" :
-    escalade_type==CONTROLLER_3WARE_678K_CHAR ? "ATA_3WARE_678K" :
-    /*             CONTROLLER_3WARE_678K     */ "ATA"             ),
+  freebsd_smart_device(),
   m_escalade_type(escalade_type), m_disknum(disknum)
 {
   set_info().info_name = strprintf("%s [3ware_disk_%02d]", dev_name, disknum);
@@ -704,7 +701,7 @@
 freebsd_highpoint_device::freebsd_highpoint_device(smart_interface * intf, const char * dev_name,
   unsigned char controller, unsigned char channel, unsigned char port)
 : smart_device(intf, dev_name, "hpt", "hpt"),
-  freebsd_smart_device("ATA")
+  freebsd_smart_device()
 {
   m_hpt_data[0] = controller; m_hpt_data[1] = channel; m_hpt_data[2] = port;
   set_info().info_name = strprintf("%s [hpt_disk_%u/%u/%u]", dev_name, m_hpt_data[0], m_hpt_data[1], m_hpt_data[2]);
@@ -897,7 +894,6 @@
   virtual bool close();
   
 private:
-  int m_fd;
   struct cam_device *m_camdev;
 };
 
@@ -921,17 +917,16 @@
 freebsd_scsi_device::freebsd_scsi_device(smart_interface * intf,
   const char * dev_name, const char * req_type)
 : smart_device(intf, dev_name, "scsi", req_type),
-  freebsd_smart_device("SCSI")
+  freebsd_smart_device()
 {
 }
 
 
 bool freebsd_scsi_device::scsi_pass_through(scsi_cmnd_io * iop)
 {
-  int report=scsi_debugmode;
   union ccb *ccb;
 
-  if (report > 0) {
+  if (scsi_debugmode) {
     unsigned int k;
     const unsigned char * ucp = iop->cmnd;
     const char * np;
@@ -940,7 +935,7 @@
     pout(" [%s: ", np ? np : "<unknown opcode>");
     for (k = 0; k < iop->cmnd_len; ++k)
       pout("%02x ", ucp[k]);
-    if ((report > 1) && 
+    if ((scsi_debugmode > 1) && 
       (DXFER_TO_DEVICE == iop->dxfer_dir) && (iop->dxferp)) {
     int trunc = (iop->dxfer_len > 256) ? 1 : 0;
 
@@ -949,18 +944,21 @@
     dStrHex(iop->dxferp, (trunc ? 256 : iop->dxfer_len) , 1);
       }
       else
-        pout("]");
+        pout("]\n");
   }
 
   if(m_camdev==NULL) {
-    warnx("error: camdev=0!");
-    return -ENOTTY;
+    if (scsi_debugmode)
+      pout("  error: camdev=0!\n");
+    return set_err(ENOTTY);
   }
 
   if (!(ccb = cam_getccb(m_camdev))) {
-    warnx("error allocating ccb");
-    return -ENOMEM;
+    if (scsi_debugmode)
+      pout("  error allocating ccb\n");
+    return set_err(ENOMEM);
   }
+
   // mfi SAT layer is known to be buggy
   if(!strcmp("mfi",m_camdev->sim_name)) {
     if (iop->cmnd[0] == SAT_ATA_PASSTHROUGH_12 || iop->cmnd[0] == SAT_ATA_PASSTHROUGH_16) { 
@@ -984,8 +982,8 @@
     sizeof(struct ccb_scsiio) - sizeof(struct ccb_hdr));
 
   cam_fill_csio(&ccb->csio,
-    /*retrires*/ 1,
-    /*cbfcnp*/ NULL,
+    /* retries */ 1,
+    /* cbfcnp */ NULL,
     /* flags */ (iop->dxfer_dir == DXFER_NONE ? CAM_DIR_NONE :(iop->dxfer_dir == DXFER_FROM_DEVICE ? CAM_DIR_IN : CAM_DIR_OUT)),
     /* tagaction */ MSG_SIMPLE_Q_TAG,
     /* dataptr */ iop->dxferp,
@@ -996,44 +994,81 @@
   memcpy(ccb->csio.cdb_io.cdb_bytes,iop->cmnd,iop->cmnd_len);
 
   if (cam_send_ccb(m_camdev,ccb) < 0) {
-    warn("error sending SCSI ccb");
-    cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
+    if (scsi_debugmode) {
+      pout("  error sending SCSI ccb\n");
+      cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
+    }
     cam_freeccb(ccb);
-    return -EIO;
+    return set_err(EIO);
+  }
+
+  if (scsi_debugmode) {
+    pout("  CAM status=0x%x, SCSI status=0x%x, resid=0x%x\n",
+         ccb->ccb_h.status, ccb->csio.scsi_status, ccb->csio.resid);
+    if ((scsi_debugmode > 1) && (DXFER_FROM_DEVICE == iop->dxfer_dir)) {
+      int trunc, len;
+
+      len = iop->dxfer_len - ccb->csio.resid;
+      trunc = (len > 256) ? 1 : 0;
+      if (len > 0) {
+        pout("  Incoming data, len=%d%s:\n", len,
+             (trunc ? " [only first 256 bytes shown]" : ""));
+        dStrHex(iop->dxferp, (trunc ? 256 : len), 1);
+      }
+      else
+        pout("  Incoming data trimmed to nothing by resid\n");
+    }
   }
 
   if (((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) && ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_SCSI_STATUS_ERROR)) {
-    cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
+    if (scsi_debugmode)
+      cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
     cam_freeccb(ccb);
-    return -EIO;
+    return set_err(EIO);
   }
 
-  if (iop->sensep) {
+  iop->resid = ccb->csio.resid;
+  iop->scsi_status = ccb->csio.scsi_status;
+  if (iop->sensep && (ccb->ccb_h.status & CAM_AUTOSNS_VALID) != 0) {
+    if (scsi_debugmode)
+      pout("  sense_len=0x%x, sense_resid=0x%x\n",
+           ccb->csio.sense_len, ccb->csio.sense_resid);
     iop->resp_sense_len = ccb->csio.sense_len - ccb->csio.sense_resid;
-    memcpy(iop->sensep,&(ccb->csio.sense_data),iop->resp_sense_len);
+    /* Some SCSI controller device drivers miscalculate the sense_resid
+       field so cap resp_sense_len on max_sense_len. */
+    if (iop->resp_sense_len > iop->max_sense_len)
+      iop->resp_sense_len = iop->max_sense_len;
+    if (iop->resp_sense_len > 0) {
+      memcpy(iop->sensep, &(ccb->csio.sense_data), iop->resp_sense_len);
+      if (scsi_debugmode) {
+        if (scsi_debugmode > 1) {
+          pout("  >>> Sense buffer, len=%zu:\n", iop->resp_sense_len);
+          dStrHex(iop->sensep, iop->resp_sense_len, 1);
+        }
+        if ((iop->sensep[0] & 0x7f) > 0x71)
+          pout("  status=0x%x: [desc] sense_key=0x%x asc=0x%x ascq=0x%x\n",
+               iop->scsi_status, iop->sensep[1] & 0xf,
+               iop->sensep[2], iop->sensep[3]);
+        else
+          pout("  status=0x%x: sense_key=0x%x asc=0x%x ascq=0x%x\n",
+               iop->scsi_status, iop->sensep[2] & 0xf,
+               iop->sensep[12], iop->sensep[13]);
+      }
+    }
+    else if (scsi_debugmode)
+      pout("  status=0x%x\n", iop->scsi_status);
   }
-
-  iop->scsi_status = ccb->csio.scsi_status;
+  else if (scsi_debugmode)
+    pout("  status=0x%x\n", iop->scsi_status);
 
   cam_freeccb(ccb);
 
-  if (report > 0) {
-    int trunc;
-
-    pout("  status=0\n");
-    trunc = (iop->dxfer_len > 256) ? 1 : 0;
-
-    pout("  Incoming data, len=%d%s:\n", (int)iop->dxfer_len,
-      (trunc ? " [only first 256 bytes shown]" : ""));
-    dStrHex(iop->dxferp, (trunc ? 256 : iop->dxfer_len) , 1);
-  }
-
   // mfip replacing PDT of the device so response does not make a sense
   // this sets PDT to 00h - direct-access block device
   if((!strcmp("mfi", m_camdev->sim_name) || !strcmp("mpt", m_camdev->sim_name))
    && iop->cmnd[0] == INQUIRY) {
-     if (report > 0) {
-        pout("device on %s controller, patching PDT\n", m_camdev->sim_name);
+     if (scsi_debugmode) {
+        pout("  device on %s controller, patching PDT\n", m_camdev->sim_name);
      }
      iop->dxferp[0] = iop->dxferp[0] & 0xe0;
   }
@@ -1077,7 +1112,7 @@
 // Areca RAID Controller(SATA Disk)
 freebsd_areca_ata_device::freebsd_areca_ata_device(smart_interface * intf, const char * dev_name, int disknum, int encnum)
 : smart_device(intf, dev_name, "areca", "areca"),
-  freebsd_smart_device("ATA")
+  freebsd_smart_device()
 {
   set_disknum(disknum);
   set_encnum(encnum);
@@ -1146,7 +1181,7 @@
 // Areca RAID Controller(SAS Device)
 freebsd_areca_scsi_device::freebsd_areca_scsi_device(smart_interface * intf, const char * dev_name, int disknum, int encnum)
 : smart_device(intf, dev_name, "areca", "areca"),
-  freebsd_smart_device("SCSI")
+  freebsd_smart_device()
 {
   set_disknum(disknum);
   set_encnum(encnum);
@@ -1220,7 +1255,7 @@
 freebsd_cciss_device::freebsd_cciss_device(smart_interface * intf,
   const char * dev_name, unsigned char disknum)
 : smart_device(intf, dev_name, "cciss", "cciss"),
-  freebsd_smart_device("SCSI"),
+  freebsd_smart_device(),
   m_disknum(disknum)
 {
   set_info().info_name = strprintf("%s [cciss_disk_%02d]", dev_name, disknum);
