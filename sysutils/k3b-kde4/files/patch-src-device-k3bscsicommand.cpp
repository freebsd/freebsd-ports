--- src/device/k3bscsicommand.cpp.orig	Wed Jan 21 11:20:11 2004
+++ src/device/k3bscsicommand.cpp	Fri Feb 13 21:03:38 2004
@@ -1,10 +1,10 @@
 /* 
  *
- * $Id: k3bscsicommand.cpp,v 1.4 2004/01/21 10:20:11 trueg Exp $
+ * $Id: k3bscsicommand.cpp,v 1.3 2003/12/31 14:15:17 trueg Exp $
  * Copyright (C) 2003 Sebastian Trueg <trueg@k3b.org>
  *
  * This file is part of the K3b project.
- * Copyright (C) 1998-2004 Sebastian Trueg <trueg@k3b.org>
+ * Copyright (C) 1998-2003 Sebastian Trueg <trueg@k3b.org>
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
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
@@ -135,6 +136,105 @@
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
+  : m_device(dev)
+{
+  clear();
+}
+
+K3bCdDevice::ScsiCommand::~ScsiCommand()
+{
+   if(cam)
+       cam_close_device(cam);
+//   if (m_fd >0)
+//       close(m_fd);
+}
+
+
+void K3bCdDevice::ScsiCommand::clear()
+{
+//   char pass[32];
+   cam=NULL;
+   memset (&ccb,0,sizeof(ccb));
+   ccb.ccb_h.func_code = XPT_GDEVLIST;
+//   if (ioctl (m_fd,CAMGETPASSTHRU,&ccb) < 0) return;
+//   sprintf (pass,"/dev/%.15s%u",ccb.cgdl.periph_name,ccb.cgdl.unit_number);
+   cam = cam_open_pass (m_device->m_passDevice.latin1(),O_RDWR,NULL);
+   kdDebug() << "(K3bCdDevice::ScsiCommand) open device " << m_device->m_passDevice << ((cam)?" succeeded.":" failed.") << endl;
+}
+
+unsigned char& K3bCdDevice::ScsiCommand::operator[]( size_t i )
+{
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
+   ccb.csio.ccb_h.flags |= dir;
+   ccb.csio.data_ptr  = (u_int8_t *)data;
+   ccb.csio.dxfer_len = len;
+   if ((ret = cam_send_ccb(cam, &ccb)) < 0)
+   {
+      kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed: " << ret << endl;
+      return -1;
+  }
+   if ((ccb.ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP)
+   {
+      kdDebug() << "(K3bCdDevice::ScsiCommand) transport succeeded" << endl;
+    return 0;
+   }
+   errno = EIO;
+   ret = ERRCODE(((unsigned char *)&ccb.csio.sense_data));
+   if (ret == 0)
+      ret = -1;
+   else
+      CREAM_ON_ERRNO(((unsigned char *)&ccb.csio.sense_data));
+   kdDebug() << "(K3bCdDevice::ScsiCommand) transport failed (2): " << ret << endl;
+   return ret;
+}
+#endif
 
 QString K3bCdDevice::MMC::commandString( const unsigned char& command )
 {
