--- libk3bdevice/k3bscsicommand_bsd.cpp.orig	Fri Jul  1 15:30:50 2005
+++ libk3bdevice/k3bscsicommand_bsd.cpp	Sun Jul 17 15:07:58 2005
@@ -51,10 +51,6 @@
 void K3bDevice::ScsiCommand::clear()
 {
   memset (&d->ccb,0,sizeof(ccb));
-  if (!m_device || !m_device->handle()) return;
-  d->ccb.ccb_h.path_id    = m_device->handle()->path_id;
-  d->ccb.ccb_h.target_id  = m_device->handle()->target_id;
-  d->ccb.ccb_h.target_lun = m_device->handle()->target_lun;
 }
 
 
@@ -76,8 +72,11 @@
     needToClose = true;
   }
 
-  if( !m_device->open( dir == TR_DIR_WRITE ) )
+  if( !m_device->open( true ) )
     return -1;
+  d->ccb.ccb_h.path_id    = m_device->handle()->path_id;
+  d->ccb.ccb_h.target_id  = m_device->handle()->target_id;
+  d->ccb.ccb_h.target_lun = m_device->handle()->target_lun;
 
   kdDebug() << "(K3bDevice::ScsiCommand) transport command " << QString::number((int)d->ccb.csio.cdb_io.cdb_bytes[0], 16) << ", length: " << (int)d->ccb.csio.cdb_len << endl;
   int ret=0;
@@ -86,7 +85,7 @@
     direction |= CAM_DIR_NONE;
   else
     direction |= (dir & TR_DIR_READ)?CAM_DIR_IN : CAM_DIR_OUT;
-  cam_fill_csio (&(d->ccb.csio), 1, 0 /* NULL */, direction | CAM_DEV_QFRZDIS, MSG_SIMPLE_Q_TAG, (u_int8_t *)data, len, sizeof(d->ccb.csio.sense_data), d->ccb.csio.cdb_len, 30*1000);
+  cam_fill_csio (&(d->ccb.csio), 1, 0 /* NULL */, direction, MSG_SIMPLE_Q_TAG, (u_int8_t *)data, len, sizeof(d->ccb.csio.sense_data), d->ccb.csio.cdb_len, 30*1000);
   unsigned char * sense = (unsigned char *)&d->ccb.csio.sense_data;
   if ((ret = cam_send_ccb(m_device->handle(), &d->ccb)) < 0)
     {
@@ -101,10 +100,11 @@
       if( needToClose )
 	m_device->close();
 
-      return( ((senset->error_code & SSD_ERRCODE)<<24) & 0xF000 |
+      int result = (((senset->error_code & SSD_ERRCODE)<<24) & 0xF000 |
 	      ((senset->flags & SSD_KEY)<<16)          & 0x0F00 |
 	      (senset->add_sense_code<<8)              & 0x00F0 |
 	      (senset->add_sense_code_qual)            & 0x000F );
+      return result?result:ret;
     }
   if ((d->ccb.ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP) {
     if( needToClose )
