--- src/core/device/k3bscsicommand.cpp.orig	Mon Sep  1 12:20:02 2003
+++ src/core/device/k3bscsicommand.cpp	Fri Nov  7 12:35:44 2003
@@ -14,33 +14,70 @@
  */
 
 #include "k3bscsicommand.h"
-
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
 #include <kdebug.h>
 
 #include <string.h>
 #include <sys/ioctl.h>
 
 
-K3bCdDevice::ScsiCommand::ScsiCommand( int fd )
-  : m_fd(fd)
+K3bCdDevice::ScsiCommand::ScsiCommand( const QString & passDevice )
+  : m_passDevice(passDevice)
 {
   clear();
 }
 
+K3bCdDevice::ScsiCommand::~ScsiCommand()
+{
+   if(cam)
+       cam_close_device(cam);
+//   if (m_fd >0)
+//       close(m_fd);
+}
+
 
 void K3bCdDevice::ScsiCommand::clear()
 {
-  ::memset( &m_cmd, 0, sizeof(struct cdrom_generic_command) );
-  ::memset( &m_sense, 0, sizeof(struct request_sense) );
-
-  m_cmd.quiet = 1;
-  m_cmd.sense = &m_sense;
+//   char pass[32];
+   cam=NULL;
+   memset (&ccb,0,sizeof(ccb));
+   ccb.ccb_h.func_code = XPT_GDEVLIST;
+//   if (ioctl (m_fd,CAMGETPASSTHRU,&ccb) < 0) return;
+//   sprintf (pass,"/dev/%.15s%u",ccb.cgdl.periph_name,ccb.cgdl.unit_number);
+   cam = cam_open_pass (m_passDevice.latin1(),O_RDWR,NULL);
+   kdDebug() << "(K3bCdDevice::ScsiCommand) open device " << m_passDevice << ((cam)?" succeeded.":" failed.") << endl;
 }
 
-
 unsigned char& K3bCdDevice::ScsiCommand::operator[]( size_t i )
 {
-  return m_cmd.cmd[i];
+   if (!i && cam)
+   {
+      memset(&ccb,0,sizeof(ccb));
+      ccb.ccb_h.path_id    = cam->path_id;
+      ccb.ccb_h.target_id  = cam->target_id;
+      ccb.ccb_h.target_lun = cam->target_lun;
+      cam_fill_csio (&(ccb.csio), 1, NULL, CAM_DEV_QFRZDIS, MSG_SIMPLE_Q_TAG, NULL, 0, sizeof(ccb.csio.sense_data), 0, 30*1000);
+   }
+   ccb.csio.cdb_len = i+1;
+   return ccb.csio.cdb_io.cdb_bytes[i];
 }
 
 
@@ -48,20 +85,29 @@
 					 void* data,
 					 size_t len )
 {
-  m_cmd.buffer = (unsigned char*)data;
-  m_cmd.buflen = len;
-  if( dir == TR_DIR_READ )
-    m_cmd.data_direction = CGC_DATA_READ;
-  else if( dir == TR_DIR_WRITE )
-    m_cmd.data_direction = CGC_DATA_WRITE;
-  else
-    m_cmd.data_direction = CGC_DATA_NONE;
-
-  if( ::ioctl( m_fd, CDROM_SEND_PACKET, &m_cmd ) ) {
-    kdDebug() << "(K3bCdDevice::ScsiCommand) failed: fd: " << m_fd 
-	      << " errorcode: " << m_sense.error_code << endl;
-    return ( m_sense.error_code != 0 ? m_sense.error_code : -1 );
+   if (!cam)
+      return -1;
+   kdDebug() << "(K3bCdDevice::ScsiCommand) transport command " << QString::number((int)ccb.csio.cdb_io.cdb_bytes[0], 16) << ", length: " << (int)ccb.csio.cdb_len << endl;
+   int ret=0;
+   ccb.csio.ccb_h.flags |= dir;
+   ccb.csio.data_ptr  = (u_int8_t *)data;
+   ccb.csio.dxfer_len = len;
+   if ((ret = cam_send_ccb(cam, &ccb)) < 0)
+   {
+      kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed: " << ret << endl;
+      return -1;
   }
-  else
+   if ((ccb.ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP)
+   {
+      kdDebug() << "(K3bCdDevice::ScsiCommand) transport succeeded" << endl;
     return 0;
+   }
+   errno = EIO;
+   ret = ERRCODE(((unsigned char *)&ccb.csio.sense_data));
+   if (ret == 0)
+      ret = -1;
+   else
+      CREAM_ON_ERRNO(((unsigned char *)&ccb.csio.sense_data));
+   kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed (2): " << ret << endl;
+   return ret;
 }
