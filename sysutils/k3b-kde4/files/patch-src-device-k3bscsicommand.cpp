--- src/device/k3bscsicommand.cpp.orig	Sun Aug 15 11:58:23 2004
+++ src/device/k3bscsicommand.cpp	Sun Jan  2 09:30:08 2005
@@ -58,13 +58,14 @@
 
 
 
-K3bCdDevice::ScsiCommand::ScsiCommand( int fd )
-  : m_fd(fd),
-    m_device(0)
-{
-  clear();
-}
+//K3bCdDevice::ScsiCommand::ScsiCommand( int fd )
+//  : m_fd(fd),
+//    m_device(0)
+//{
+//  clear();
+//}
 
+#ifndef __FreeBSD__
 
 K3bCdDevice::ScsiCommand::ScsiCommand( const K3bCdDevice::CdDevice* dev )
   : m_device(dev)
@@ -141,6 +142,155 @@
     return 0;
 }
 
+#else
+
+#include <fcntl.h>
+#include <cam/scsi/scsi_message.h>
+#include <cam/scsi/scsi_pass.h>
+#include <errno.h>
+#define ERRCODE(s)	((((s)[2]&0x0F)<<16)|((s)[12]<<8)|((s)[13]))
+#define EMEDIUMTYPE	EINVAL
+#define	ENOMEDIUM	ENODEV
+#define CREAM_ON_ERRNO(s)	do {			\
+    switch ((s)[12])					\
+    {	case 0x04:	errno=EAGAIN;	break;		\
+	case 0x20:	errno=ENODEV;	break;		\
+	case 0x21:	if ((s)[13]==0)	errno=ENOSPC;	\
+			else		errno=EINVAL;	\
+			break;				\
+	case 0x30:	errno=EMEDIUMTYPE;  break;	\
+	case 0x3A:	errno=ENOMEDIUM;    break;	\
+    }							\
+} while(0)
+#include <unistd.h>
+#include <kdebug.h>
+
+#include <string.h>
+#include <sys/ioctl.h>
+
+K3bCdDevice::ScsiCommand::ScsiCommand( const K3bCdDevice::CdDevice* dev )
+  : closecam(true), m_device(dev)
+{
+   cam = cam_open_pass (m_device->m_passDevice.latin1(),O_RDWR,NULL);
+   kdDebug() << "(K3bCdDevice::ScsiCommand) open device " << m_device->m_passDevice << ((cam)?" succeeded.":" failed.") << endl;
+   clear();
+}
+
+K3bCdDevice::ScsiCommand::ScsiCommand( const K3bCdDevice::CdDevice* dev, struct cam_device * c)
+  : closecam(false), cam(c), m_device(dev)
+{
+   clear();
+}
+
+K3bCdDevice::ScsiCommand::~ScsiCommand()
+{
+   if(cam && closecam)
+   {
+       cam_close_device(cam);
+       kdDebug() << "(K3bCdDevice::ScsiCommand) device " << m_device->m_passDevice << " closed." << endl;
+   }
+}
+
+
+void K3bCdDevice::ScsiCommand::clear()
+{
+   memset (&ccb,0,sizeof(ccb));
+   if (!cam)
+      return;
+   ccb.ccb_h.path_id    = cam->path_id;
+   ccb.ccb_h.target_id  = cam->target_id;
+   ccb.ccb_h.target_lun = cam->target_lun;
+}
+
+unsigned char& K3bCdDevice::ScsiCommand::operator[]( size_t i )
+{
+   ccb.csio.cdb_len = i+1;
+   return ccb.csio.cdb_io.cdb_bytes[i];
+}
+
+
+int K3bCdDevice::ScsiCommand::transport( TransportDirection dir,
+					 void* data,
+					 size_t len )
+{
+   if (!cam)
+      return -1;
+   kdDebug() << "(K3bCdDevice::ScsiCommand) transport command " << QString::number((int)ccb.csio.cdb_io.cdb_bytes[0], 16) << ", length: " << (int)ccb.csio.cdb_len << endl;
+   int ret=0;
+   unsigned char command = ccb.csio.cdb_io.cdb_bytes[0];
+   int direction = CAM_DEV_QFRZDIS;
+   if (!len)
+      direction |= CAM_DIR_NONE;
+   else
+      direction |= (dir & TR_DIR_READ)?CAM_DIR_IN : CAM_DIR_OUT;
+   cam_fill_csio (&(ccb.csio), 1, NULL, direction | CAM_DEV_QFRZDIS, MSG_SIMPLE_Q_TAG, (u_int8_t *)data, len, sizeof(ccb.csio.sense_data), ccb.csio.cdb_len, 30*1000);
+   unsigned char * sense = (unsigned char *)&ccb.csio.sense_data;
+   if ((ret = cam_send_ccb(cam, &ccb)) < 0)
+   {
+      kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed: " << ret << endl;
+      goto dump_error;
+  }
+   if ((ccb.ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP)
+      return 0;
+   
+   errno = EIO;
+   // FreeBSD 5-CURRENT since 2003-08-24, including 5.2 fails to
+   // pull sense data automatically, at least for ATAPI transport,
+   // so I reach for it myself...
+   if ((ccb.csio.scsi_status==SCSI_STATUS_CHECK_COND) &&
+      !(ccb.ccb_h.status&CAM_AUTOSNS_VALID))
+   {   
+      u_int8_t  _sense[18];
+      u_int32_t resid=ccb.csio.resid;
+
+      memset(_sense,0,sizeof(_sense));
+
+      operator[](0)      = 0x03;	// REQUEST SENSE
+      ccb.csio.cdb_io.cdb_bytes[4] = sizeof(_sense);
+      ccb.csio.cdb_len   = 6;
+      ccb.csio.ccb_h.flags |= CAM_DIR_IN|CAM_DIS_AUTOSENSE;
+      ccb.csio.data_ptr  = _sense;
+      ccb.csio.dxfer_len = sizeof(_sense);
+      ccb.csio.sense_len = 0;
+      ret = cam_send_ccb(cam, &ccb);
+
+      ccb.csio.resid = resid;
+      if (ret<0)
+      {
+         kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed (2): " << ret << endl;
+         ret = -1;
+         goto dump_error;
+      }
+      if ((ccb.ccb_h.status&CAM_STATUS_MASK) != CAM_REQ_CMP)
+      {
+         kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed (3): " << ret << endl;
+         errno=EIO,-1;
+         ret = -1;
+         goto dump_error;
+      } 
+
+      memcpy(sense,_sense,sizeof(_sense));
+   }
+
+   ret = ERRCODE(sense);
+   kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed (4): " << ret << endl;
+   if (ret == 0)
+      ret = -1;
+   else
+      CREAM_ON_ERRNO(((unsigned char *)&ccb.csio.sense_data));
+dump_error:
+    kdDebug() << "(K3bCdDevice::ScsiCommand) failed: " << endl
+              << "                           command:    " << QString("%1 (%2)")
+      .arg( MMC::commandString( ccb.csio.cdb_io.cdb_bytes[0] ) )
+      .arg( QString::number(ccb.csio.cdb_io.cdb_bytes[0], 16) ) << endl
+              << "                           errorcode:  " << QString::number(((struct scsi_sense_data *)sense)->error_code & SSD_ERRCODE, 16) << endl
+              << "                           sense key:  " << senseKeyToString(((struct scsi_sense_data *)sense)->flags & SSD_KEY) << endl
+              << "                           asc:        " << QString::number(((struct scsi_sense_data *)sense)->add_sense_code, 16) << endl
+              << "                           ascq:       " << QString::number(((struct scsi_sense_data *)sense)->add_sense_code_qual, 16) << endl;
+   
+   return ret;
+}
+#endif
 
 QString K3bCdDevice::MMC::commandString( const unsigned char& command )
 {
