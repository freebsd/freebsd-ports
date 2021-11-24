--- os_freebsd.cpp.orig	2020-12-12 21:36:48 UTC
+++ os_freebsd.cpp
@@ -26,6 +26,7 @@
 #endif
 #include <sys/stat.h>
 #include <unistd.h>
+#include <sys/uio.h>
 #include <glob.h>
 #include <stddef.h>
 #include <paths.h>
@@ -199,6 +200,9 @@ static const char  smartctl_examples[] =
   "  smartctl -a --device=areca,3/1 /dev/arcmsr0\n"
          "                              (Prints all SMART information for 3rd disk in the 1st enclosure \n"
          "                               on first ARECA RAID controller)\n"
+  "  smartctl -a --device=megaraid,3 /dev/mrsas0\n"
+         "                              (Prints all SMART information for 3rd disk\n"
+         "                               on first LSI RAID controller)\n"
 
          ;
 
@@ -761,7 +765,240 @@ bool freebsd_escalade_device::ata_pass_through(const a
   return true;
 }
 
+/////////////////////////////////////////////////////////////////////////////
+/// LSI MegaRAID support
 
+class freebsd_megaraid_device
+: public /* implements */ scsi_device,
+  public /* extends */ freebsd_smart_device
+{
+public:
+  freebsd_megaraid_device(smart_interface *intf, const char *name,
+    unsigned int tgt);
+
+  virtual ~freebsd_megaraid_device();
+
+  virtual smart_device * autodetect_open() override;
+
+  virtual bool open() override;
+  virtual bool close() override;
+
+  virtual bool scsi_pass_through(scsi_cmnd_io *iop) override;
+
+private:
+  unsigned int m_disknum;
+  unsigned int m_hba;
+  int m_fd;
+
+  bool (freebsd_megaraid_device::*pt_cmd)(int cdblen, void *cdb, int dataLen, void *data,
+    int senseLen, void *sense, int report, int direction, int timeout);
+  bool megasas_cmd(int cdbLen, void *cdb, int dataLen, void *data,
+    int senseLen, void *sense, int report, int direction, int timeout);
+};
+
+freebsd_megaraid_device::freebsd_megaraid_device(smart_interface *intf,
+  const char *dev_name, unsigned int tgt)
+ : smart_device(intf, dev_name, "megaraid", "megaraid"),
+   freebsd_smart_device(),
+   m_disknum(tgt), m_hba(0),
+   m_fd(-1), pt_cmd(0)
+{
+  set_info().info_name = strprintf("%s [megaraid_disk_%02d]", dev_name, m_disknum);
+  set_info().dev_type = strprintf("megaraid,%d", tgt);
+}
+
+freebsd_megaraid_device::~freebsd_megaraid_device()
+{
+  if (m_fd >= 0)
+    ::close(m_fd);
+}
+
+smart_device * freebsd_megaraid_device::autodetect_open()
+{
+  int report = scsi_debugmode;
+
+  // Open device
+  if (!open())
+    return this;
+
+  // The code below is based on smartd.cpp:SCSIFilterKnown()
+  if (strcmp(get_req_type(), "megaraid"))
+    return this;
+
+  // Get INQUIRY
+  unsigned char req_buff[64] = {0, };
+  int req_len = 36;
+  if (scsiStdInquiry(this, req_buff, req_len)) {
+      close();
+      set_err(EIO, "INQUIRY failed");
+      return this;
+  }
+
+  int avail_len = req_buff[4] + 5;
+  int len = (avail_len < req_len ? avail_len : req_len);
+  if (len < 36)
+      return this;
+
+  if (report)
+    pout("Got MegaRAID inquiry.. %s\n", req_buff+8);
+
+  // Use INQUIRY to detect type
+  {
+    // SAT?
+    ata_device * newdev = smi()->autodetect_sat_device(this, req_buff, len);
+    if (newdev) // NOTE: 'this' is now owned by '*newdev'
+      return newdev;
+  }
+
+  // Nothing special found
+  return this;
+}
+
+bool freebsd_megaraid_device::open()
+{
+  /* Open Device IOCTL node */
+  if ((m_fd = ::open(get_dev_name(), O_RDWR)) >= 0) {
+    pt_cmd = &freebsd_megaraid_device::megasas_cmd;
+  }
+  else {
+    int err = errno;
+    freebsd_smart_device::close();
+    return set_err(err, "cannot open %s",get_dev_name());
+  }
+  set_fd(m_fd);
+  return true;
+}
+
+bool freebsd_megaraid_device::close()
+{
+  if (m_fd >= 0)
+    ::close(m_fd);
+  m_fd = -1; m_hba = 0; pt_cmd = 0;
+  set_fd(m_fd);
+  return true;
+}
+
+bool freebsd_megaraid_device::scsi_pass_through(scsi_cmnd_io *iop)
+{
+  int report = scsi_debugmode;
+
+  if (report > 0) {
+        int k, j;
+        const unsigned char * ucp = iop->cmnd;
+        const char * np;
+        char buff[256];
+        const int sz = (int)sizeof(buff);
+
+        np = scsi_get_opcode_name(ucp[0]);
+        j = snprintf(buff, sz, " [%s: ", np ? np : "<unknown opcode>");
+        for (k = 0; k < (int)iop->cmnd_len; ++k)
+            j += snprintf(&buff[j], (sz > j ? (sz - j) : 0), "%02x ", ucp[k]);
+        if ((report > 1) &&
+            (DXFER_TO_DEVICE == iop->dxfer_dir) && (iop->dxferp)) {
+            int trunc = (iop->dxfer_len > 256) ? 1 : 0;
+
+            snprintf(&buff[j], (sz > j ? (sz - j) : 0), "]\n  Outgoing "
+                     "data, len=%d%s:\n", (int)iop->dxfer_len,
+                     (trunc ? " [only first 256 bytes shown]" : ""));
+            dStrHex(iop->dxferp, (trunc ? 256 : iop->dxfer_len) , 1);
+        }
+        else
+            snprintf(&buff[j], (sz > j ? (sz - j) : 0), "]\n");
+        pout("%s", buff);
+  }
+
+  // Controller rejects Test Unit Ready
+  if (iop->cmnd[0] == 0x00)
+    return true;
+
+  if (iop->cmnd[0] == SAT_ATA_PASSTHROUGH_12 || iop->cmnd[0] == SAT_ATA_PASSTHROUGH_16) {
+    // Controller does not return ATA output registers in SAT sense data
+    if (iop->cmnd[2] & (1 << 5)) // chk_cond
+      return set_err(ENOSYS, "ATA return descriptor not supported by controller firmware");
+  }
+  // SMART WRITE LOG SECTOR causing media errors
+  if ((iop->cmnd[0] == SAT_ATA_PASSTHROUGH_16 // SAT16 WRITE LOG
+      && iop->cmnd[14] == ATA_SMART_CMD && iop->cmnd[3]==0 && iop->cmnd[4] == ATA_SMART_WRITE_LOG_SECTOR) ||
+      (iop->cmnd[0] == SAT_ATA_PASSTHROUGH_12 // SAT12 WRITE LOG
+       && iop->cmnd[9] == ATA_SMART_CMD && iop->cmnd[3] == ATA_SMART_WRITE_LOG_SECTOR))
+  {
+    if(!failuretest_permissive)
+       return set_err(ENOSYS, "SMART WRITE LOG SECTOR may cause problems, try with -T permissive to force");
+  }
+  if (pt_cmd == NULL)
+    return false;
+  return (this->*pt_cmd)(iop->cmnd_len, iop->cmnd,
+    iop->dxfer_len, iop->dxferp,
+    iop->max_sense_len, iop->sensep, report, iop->dxfer_dir, iop->timeout);
+}
+
+bool freebsd_megaraid_device::megasas_cmd(int cdbLen, void *cdb,
+  int dataLen, void *data,
+  int senseLen, void * sense, int /*report*/, int dxfer_dir, int timeout)
+{
+  struct mfi_pass_frame * pthru;
+  struct mfi_ioc_packet uio;
+
+  pthru = (struct mfi_pass_frame *)&uio.mfi_frame.raw;
+  memset(&uio, 0, sizeof(uio));
+
+  pthru->header.cmd = MFI_CMD_PD_SCSI_IO;
+  pthru->header.cmd_status = 0;
+  pthru->header.scsi_status = 0x0;
+  pthru->header.target_id = m_disknum;
+  pthru->header.lun_id = 0; // FIXME, should be bus number?
+
+  pthru->header.sense_len = senseLen;
+  pthru->sense_addr_lo = (uintptr_t)sense ;
+  pthru->sense_addr_hi = (uintptr_t)((uint64_t)sense >> 32);
+
+  pthru->header.cdb_len = cdbLen;
+  pthru->header.timeout = timeout;
+  switch (dxfer_dir) {
+    case DXFER_FROM_DEVICE:
+      pthru->header.flags =  MFI_FRAME_DIR_READ;
+      break;
+    case DXFER_TO_DEVICE:
+      pthru->header.flags =  MFI_FRAME_DIR_WRITE;
+      break;
+    case DXFER_NONE:
+      pthru->header.flags =  MFI_FRAME_DIR_NONE;
+      break;
+  }
+
+  if (dataLen > 0) {
+    uio.mfi_sge_count = 1;
+    uio.mfi_sgl_off = offsetof(struct mfi_pass_frame,sgl);
+    uio.mfi_sgl[0].iov_base = data;
+    uio.mfi_sgl[0].iov_len = dataLen;
+
+    pthru->header.sg_count = 1;
+    pthru->header.data_len = dataLen;
+    // tested on amd64 kernel in native and 32bit mode
+    pthru->sgl.sg64[0].addr = (intptr_t)data;
+    pthru->sgl.sg64[0].len = (uint32_t)dataLen;
+  }
+  memcpy(pthru->cdb, cdb, cdbLen);
+
+  uio.mfi_adapter_no = m_hba;
+  uio.mfi_sense_len = senseLen;
+  uio.mfi_sense_off = offsetof(struct mfi_pass_frame, sense_addr_lo);
+
+  errno = 0;
+  int rc = ioctl(m_fd, MFI_CMD, &uio);
+
+  if (pthru->header.cmd_status || rc != 0) {
+    if (pthru->header.cmd_status == 12) {
+      return set_err(EIO, "megasas_cmd: Device %d does not exist\n", m_disknum);
+    }
+    return set_err((errno ? errno : EIO), "megasas_cmd result: %d.%d = %d/%d",
+                   m_hba, m_disknum, errno,
+                   pthru->header.cmd_status);
+  }
+  return true;
+}
+
+
 /////////////////////////////////////////////////////////////////////////////
 /// Implement Highpoint RAID support with old functions
 
@@ -1401,6 +1638,15 @@ smart_device * freebsd_scsi_device::autodetect_open()
     return this;
   }
 
+  // DELL?
+  if (!memcmp(req_buff + 8, "DELL    PERC", 12) || !memcmp(req_buff + 8, "MegaRAID", 8)
+      || !memcmp(req_buff + 16, "PERC H", 6) || !memcmp(req_buff + 8, "LSI\0",4)
+  ) {
+    close();
+    set_err(EINVAL, "DELL or MegaRaid controller, use '-d megaraid,N'");
+    return this;
+  }
+
   // SAT or USB, skip MFI controllers because of bugs
   {
     smart_device * newdev = smi()->autodetect_sat_device(this, req_buff, len);
@@ -1453,6 +1699,10 @@ class freebsd_smart_interface (protected)
   virtual std::string get_valid_custom_dev_types_str();
 private:
   bool get_nvme_devlist(smart_device_list & devlist, const char * type);
+  bool get_dev_megaraid(smart_device_list & devlist);
+  int megaraid_pd_add_list(const char * devname, smart_device_list & devlist);
+  int megaraid_dcmd_cmd(const char * devname, uint32_t opcode, void *buf,
+    size_t bufsize, uint8_t *mbox, size_t mboxlen, uint8_t *statusp);
 };
 
 
@@ -1775,6 +2025,9 @@ bool freebsd_smart_interface::scan_smart_devices(smart
     }
   }
 
+  // add devices from LSI MegaRaid controllers
+  get_dev_megaraid(devlist);
+
   if (scan_nvme)
     get_nvme_devlist(devlist, type);
   return true;
@@ -1800,6 +2053,114 @@ bool freebsd_smart_interface::get_nvme_devlist(smart_d
   return true;
 }
 
+// getting devices from LSI SAS MegaRaid, if available
+bool freebsd_smart_interface::get_dev_megaraid(smart_device_list & devlist)
+{
+  /* Scanning of disks on MegaRaid device */
+  char ctrlpath[64];
+
+  // trying to add devices on first 32 buses, same as StorCLI does
+  for(unsigned i = 0; i <=32; i++) {
+      sprintf(ctrlpath, "%s%u", MFI_CTRLR_PREFIX, i);
+      megaraid_pd_add_list(ctrlpath, devlist);
+      sprintf(ctrlpath, "%s%u", MRSAS_CTRLR_PREFIX, i);
+      megaraid_pd_add_list(ctrlpath, devlist);
+  }
+  return true;
+}
+
+int
+freebsd_smart_interface::megaraid_dcmd_cmd(const char * devname, uint32_t opcode, void *buf,
+  size_t bufsize, uint8_t *mbox, size_t mboxlen, uint8_t *statusp)
+{
+  struct mfi_ioc_packet ioc;
+  struct mfi_dcmd_frame * dcmd;
+
+  if ((mbox != NULL && (mboxlen == 0 || mboxlen > MFI_MBOX_SIZE)) ||
+    (mbox == NULL && mboxlen != 0))
+  {
+    errno = EINVAL;
+    return (-1);
+  }
+
+  memset(&ioc, 0, sizeof(ioc));
+  dcmd = (struct mfi_dcmd_frame *)&ioc.mfi_frame.raw;
+
+  if (mbox)
+    memcpy(dcmd->mbox, mbox, mboxlen);
+  dcmd->header.cmd = MFI_CMD_DCMD;
+  dcmd->header.data_len = bufsize;
+  dcmd->opcode = opcode;
+
+  if (bufsize > 0) {
+    ioc.mfi_sge_count = 1;
+    ioc.mfi_sgl_off = offsetof(struct mfi_dcmd_frame,sgl);
+    ioc.mfi_sgl[0].iov_base = buf;
+    ioc.mfi_sgl[0].iov_len = bufsize;
+    dcmd->header.sg_count = 1;
+    dcmd->header.data_len = bufsize;
+    // tested on amd64 kernel in native and 32bit mode
+    dcmd->sgl.sg64[0].addr = (intptr_t)buf;
+    dcmd->sgl.sg64[0].len = (uint32_t)bufsize;
+  }
+
+  int fd;
+  if ((fd = ::open(devname, O_RDWR)) < 0) {
+    return (errno);
+  }
+  // We are using MFI_CMD as it seems to be supported by all LSI BSD drivers
+  int r = ioctl(fd, MFI_CMD, &ioc);
+  ::close(fd);
+  if (r < 0) {
+    return (r);
+  }
+
+  if (statusp != NULL)
+    *statusp = dcmd->header.cmd_status;
+  else if (dcmd->header.cmd_status != MFI_STAT_OK) {
+    fprintf(stderr, "command %x returned error status %x\n",
+      opcode, dcmd->header.cmd_status);
+    errno = EIO;
+    return (-1);
+  }
+  return (0);
+}
+
+int
+freebsd_smart_interface::megaraid_pd_add_list(const char * devname, smart_device_list & devlist)
+{
+  /*
+  * Keep fetching the list in a loop until we have a large enough
+  * buffer to hold the entire list.
+  */
+  mfi_pd_list * list = 0;
+  for (unsigned list_size = 1024; ; ) {
+    list = reinterpret_cast<mfi_pd_list *>(realloc(list, list_size));
+    if (!list)
+      throw std::bad_alloc();
+    memset(list, 0, list_size);
+    if (megaraid_dcmd_cmd(devname, MFI_DCMD_PD_GET_LIST, list, list_size, NULL, 0,
+      NULL) < 0)
+    {
+      free(list);
+      return (-1);
+    }
+    if (list->size <= list_size)
+      break;
+    list_size = list->size;
+  }
+
+  // adding all SCSI devices
+  for (unsigned i = 0; i < list->count; i++) {
+    if(list->addr[i].scsi_dev_type)
+      continue; /* non disk device found */
+    smart_device * dev = new freebsd_megaraid_device(this, devname, list->addr[i].device_id);
+    devlist.push_back(dev);
+  }
+  free(list);
+  return (0);
+}
+
 #if (FREEBSDVER < 800000) // without this build fail on FreeBSD 8
 static char done[USB_MAX_DEVICES];
 
@@ -2034,9 +2395,16 @@ smart_device * freebsd_smart_interface::autodetect_sma
     }
   }
   // device is LSI raid supported by mfi driver
-  if(!strncmp("/dev/mfid", test_name, strlen("/dev/mfid")))
-    set_err(EINVAL, "To monitor disks on LSI RAID load mfip.ko module and run 'smartctl -a /dev/passX' to show SMART information");
+  if(!strncmp("/dev/mfid", test_name, strlen("/dev/mfid"))) {
+    set_err(EINVAL, "To access disks on LSI RAID load mfip.ko and use /dev/passX or use -d 'megaraid,N' with /dev/mfiX devices");
+    return 0;
+  }
 
+  if(!strncmp(MFI_CTRLR_PREFIX, test_name, strlen(MFI_CTRLR_PREFIX)) || !strncmp(MRSAS_CTRLR_PREFIX, test_name, strlen(MRSAS_CTRLR_PREFIX))) {
+    set_err(EINVAL, "To access disks on %s use '-d megaraid,N' device type", test_name);
+    return 0;
+  }
+
   // form /dev/nvme* or nvme*
   if(!strncmp("/dev/nvme", test_name, strlen("/dev/nvme")))
     return new freebsd_nvme_device(this, name, "", 0 /* use default nsid */);
@@ -2142,12 +2510,16 @@ smart_device * freebsd_smart_interface::get_custom_sma
     return new freebsd_areca_ata_device(this, name, disknum, encnum);
   }
 
+  if (sscanf(type, "megaraid,%d", &disknum) == 1) {
+    return new freebsd_megaraid_device(this, name, disknum);
+  }
+
   return 0;
 }
 
 std::string freebsd_smart_interface::get_valid_custom_dev_types_str()
 {
-  return "3ware,N, hpt,L/M/N, cciss,N, areca,N/E"
+  return "3ware,N, hpt,L/M/N, cciss,N, areca,N/E, megaraid,N"
 #if FREEBSDVER > 800100
   ", atacam"
 #endif
