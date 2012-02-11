diff --git a/libk3bdevice/k3bscsicommand_bsd.cpp b/libk3bdevice/k3bscsicommand_bsd.cpp
index ce6508e..63a8fd5 100644
--- ./libk3bdevice/k3bscsicommand_bsd.cpp
+++ ./libk3bdevice/k3bscsicommand_bsd.cpp
@@ -1,6 +1,7 @@
 /*
  *
  * Copyright (C) 2003-2009 Sebastian Trueg <trueg@k3b.org>
+ * Copyright (C) 2011 Andriy Gapon <avg@FreeBSD.org>
  *
  * This file is part of the K3b project.
  * Copyright (C) 1998-2009 Sebastian Trueg <trueg@k3b.org>
@@ -23,41 +24,43 @@
 #include <cam/scsi/scsi_message.h>
 #include <cam/scsi/scsi_pass.h>
 
-#define ERRCODE(s)	((((s)[2]&0x0F)<<16)|((s)[12]<<8)|((s)[13]))
-#define EMEDIUMTYPE	EINVAL
-#define	ENOMEDIUM	ENODEV
-#define CREAM_ON_ERRNO(s)	do {                    \
-        switch ((s)[12])                            \
-        {	case 0x04:	errno=EAGAIN;	break;		\
-        case 0x20:	errno=ENODEV;	break;          \
-        case 0x21:	if ((s)[13]==0)	errno=ENOSPC;	\
-			else		errno=EINVAL;               \
-			break;                                  \
-        case 0x30:	errno=EMEDIUMTYPE;  break;      \
-        case 0x3A:	errno=ENOMEDIUM;    break;      \
-        }                                           \
-    } while(0)
-
+namespace /*anonymous*/
+{
+    inline int sense_to_err( const struct scsi_sense_data& s )
+    {
+        int errorCode, senseKey, addSenseCode, addSenseCodeQual;
+        scsi_extract_sense( (struct scsi_sense_data*) &s, &errorCode,
+                            &senseKey, &addSenseCode, &addSenseCodeQual );
+        return (errorCode << 24) | (senseKey << 16) |
+	       (addSenseCode << 8) | addSenseCodeQual;
+    }
+}
 
 
 class K3b::Device::ScsiCommand::Private
 {
+    typedef union ccb CCB;
+
 public:
-    union ccb ccb;
+    Private();
+    int transport( const Device* device, TransportDirection dir, void* data, size_t len );
+    unsigned char& operator[]( size_t i );
+    void clear();
+    const CCB& get_ccb() { return ccb; }
+
+private:
+    CCB ccb;
 };
 
 
 void K3b::Device::ScsiCommand::clear()
 {
-    memset (&d->ccb,0,sizeof(ccb));
+    d->clear();
 }
 
-
 unsigned char& K3b::Device::ScsiCommand::operator[]( size_t i )
 {
-    if( d->ccb.csio.cdb_len < i+1 )
-        d->ccb.csio.cdb_len = i+1;
-    return d->ccb.csio.cdb_io.cdb_bytes[i];
+    return (*d)[i];
 }
 
 int K3b::Device::ScsiCommand::transport( TransportDirection dir,
@@ -78,130 +81,102 @@ int K3b::Device::ScsiCommand::transport( TransportDirection dir,
         m_device->usageUnlock();
         return -1;
     }
-    d->ccb.ccb_h.path_id    = m_device->handle()->path_id;
-    d->ccb.ccb_h.target_id  = m_device->handle()->target_id;
-    d->ccb.ccb_h.target_lun = m_device->handle()->target_lun;
 
-    kDebug() << "(K3b::Device::ScsiCommand) transport command " << QString::number((int)d->ccb.csio.cdb_io.cdb_bytes[0], 16) << ", length: " << (int)d->ccb.csio.cdb_len;
-    int ret=0;
-    int direction = CAM_DEV_QFRZDIS;
-    if (!len)
-        direction |= CAM_DIR_NONE;
-    else
-        direction |= (dir & TR_DIR_READ)?CAM_DIR_IN : CAM_DIR_OUT;
-    cam_fill_csio (&(d->ccb.csio), 1, 0 /* NULL */, direction, MSG_SIMPLE_Q_TAG, (u_int8_t *)data, len, sizeof(d->ccb.csio.sense_data), d->ccb.csio.cdb_len, 30*1000);
-    unsigned char * sense = (unsigned char *)&d->ccb.csio.sense_data;
+    int ret = d->transport( m_device, dir, data, len );
+    if( ret != 0 ) {
+        const struct scsi_sense_data& s = d->get_ccb().csio.sense_data;
+        int errorCode, senseKey, addSenseCode, addSenseCodeQual;
+        scsi_extract_sense( (struct scsi_sense_data*) &s, &errorCode, &senseKey,
+                            &addSenseCode, &addSenseCodeQual );
+        debugError( d->get_ccb().csio.cdb_io.cdb_bytes[0],
+                    errorCode,
+                    senseKey,
+                    addSenseCode,
+                    addSenseCodeQual );
+    }
 
-    ret = cam_send_ccb(m_device->handle(), &d->ccb);
+    if( needToClose )
+        m_device->close();
+    m_device->usageUnlock();
 
-    if (ret < 0) {
-        kDebug() << "(K3b::Device::ScsiCommand) transport failed: " << ret;
+    return ret;
+}
 
-        if( needToClose )
-            m_device->close();
+K3b::Device::ScsiCommand::Private::Private()
+{
+    clear();
+}
 
-        m_device->usageUnlock();
+void K3b::Device::ScsiCommand::Private::clear()
+{
+    memset( &ccb, 0, sizeof(ccb) );
+}
 
-        struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-        debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                    senset->error_code & SSD_ERRCODE,
-                    senset->flags & SSD_KEY,
-                    senset->add_sense_code,
-                    senset->add_sense_code_qual );
+unsigned char& K3b::Device::ScsiCommand::Private::operator[]( size_t i )
+{
+    if( ccb.csio.cdb_len < i + 1 )
+        ccb.csio.cdb_len = i + 1;
+    return ccb.csio.cdb_io.cdb_bytes[i];
+}
 
-        int result = (((senset->error_code & SSD_ERRCODE)<<24) & 0xF000 |
-                      ((senset->flags & SSD_KEY)<<16)          & 0x0F00 |
-                      (senset->add_sense_code<<8)              & 0x00F0 |
-                      (senset->add_sense_code_qual)            & 0x000F );
+int K3b::Device::ScsiCommand::Private::transport( const Device* device, TransportDirection dir, void* data, size_t len )
+{
+    ccb.ccb_h.path_id    = device->handle()->path_id;
+    ccb.ccb_h.target_id  = device->handle()->target_id;
+    ccb.ccb_h.target_lun = device->handle()->target_lun;
 
-        return result ? result : ret;
+    kDebug() << "(K3b::Device::ScsiCommand) transport command " << commandString(ccb.csio.cdb_io.cdb_bytes[0])
+             << " (" << QString::number((int)ccb.csio.cdb_io.cdb_bytes[0], 16) << "), length: " << (int)ccb.csio.cdb_len;
+    int direction = CAM_DEV_QFRZDIS;
+    if (!len)
+        direction |= CAM_DIR_NONE;
+    else
+        direction |= (dir & TR_DIR_READ) ? CAM_DIR_IN : CAM_DIR_OUT;
+
+    cam_fill_csio( &(ccb.csio), 1, NULL, direction, MSG_SIMPLE_Q_TAG, (uint8_t*)data, len, sizeof(ccb.csio.sense_data), ccb.csio.cdb_len, 30*1000 );
+    int ret = cam_send_ccb( device->handle(), &ccb );
+    if( ret < 0 ) {
+        kError() << "(K3b::Device::ScsiCommand) transport cam_send_ccb failed: ret = " << ret
+                 << ", errno = " << errno << ", cam_errbuf = " << cam_errbuf;
+        return 1;
     }
-
-    else if ((d->ccb.ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP) {
-        if( needToClose )
-            m_device->close();
-        m_device->usageUnlock();
+    else if( (ccb.ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP ) {
+        kDebug() << "(K3b::Device::ScsiCommand) transport succeeded";
         return 0;
     }
 
-    errno = EIO;
-    // FreeBSD 5-CURRENT since 2003-08-24, including 5.2 fails to
-    // pull sense data automatically, at least for ATAPI transport,
-    // so I reach for it myself...
-    if ((d->ccb.csio.scsi_status==SCSI_STATUS_CHECK_COND) &&
-        !(d->ccb.ccb_h.status&CAM_AUTOSNS_VALID))
-    {
-        u_int8_t  _sense[18];
-        u_int32_t resid=d->ccb.csio.resid;
-
-        memset(_sense,0,sizeof(_sense));
+    kDebug() << "(K3b::Device::ScsiCommand) transport command failed: scsi_status = " << QString::number(ccb.csio.scsi_status, 16);
 
-        operator[](0)      = 0x03;	// REQUEST SENSE
-        d->ccb.csio.cdb_io.cdb_bytes[4] = sizeof(_sense);
-        d->ccb.csio.cdb_len   = 6;
-        d->ccb.csio.ccb_h.flags |= CAM_DIR_IN|CAM_DIS_AUTOSENSE;
-        d->ccb.csio.data_ptr  = _sense;
-        d->ccb.csio.dxfer_len = sizeof(_sense);
-        d->ccb.csio.sense_len = 0;
+    if( ccb.csio.scsi_status == SCSI_STATUS_CHECK_COND &&
+        !(ccb.ccb_h.status & CAM_AUTOSNS_VALID) &&
+        ccb.csio.cdb_io.cdb_bytes[0] != MMC_REQUEST_SENSE )
+    {
+        kDebug() << "(K3b::Device::ScsiCommand) transport requesting sense data";
 
-        ret = cam_send_ccb(m_device->handle(), &d->ccb);
+        struct scsi_sense_data sense;
+        ScsiCommand::Private cmd;
+        cmd[0] = MMC_REQUEST_SENSE;
+        cmd[4] = SSD_MIN_SIZE;
+        cmd[5] = 0; // Necessary to set the proper command length
 
-        d->ccb.csio.resid = resid;
-        if (ret<0)
-        {
-            kDebug() << "(K3b::Device::ScsiCommand) transport failed (2): " << ret;
-            ret = -1;
-            struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-            debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                        senset->error_code & SSD_ERRCODE,
-                        senset->flags & SSD_KEY,
-                        senset->add_sense_code,
-                        senset->add_sense_code_qual );
-
-            if( needToClose )
-                m_device->close();
-            m_device->usageUnlock();
-
-            return -1;
-        }
-        if ((d->ccb.ccb_h.status&CAM_STATUS_MASK) != CAM_REQ_CMP)
+        memset( &sense, 0, sizeof(sense) );
+        ret = cmd.transport( device, TR_DIR_READ, &sense, SSD_MIN_SIZE );
+        if( ret < 0 )
         {
-            kDebug() << "(K3b::Device::ScsiCommand) transport failed (3): " << ret;
-            errno=EIO,-1;
-            ret = -1;
-            struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-            debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                        senset->error_code & SSD_ERRCODE,
-                        senset->flags & SSD_KEY,
-                        senset->add_sense_code,
-                        senset->add_sense_code_qual );
-
-            if( needToClose )
-                m_device->close();
-            m_device->usageUnlock();
-
-            return -1;
+            kWarning() << "(K3b::Device::ScsiCommand) transport getting sense data failed: " << ret;
+            return 1;
         }
 
-        memcpy(sense,_sense,sizeof(_sense));
+        ccb.csio.sense_data = sense;
+        ccb.ccb_h.status |= CAM_AUTOSNS_VALID;
     }
 
-    ret = ERRCODE(sense);
-    kDebug() << "(K3b::Device::ScsiCommand) transport failed (4): " << ret;
-    if (ret == 0)
-        ret = -1;
-    else
-        CREAM_ON_ERRNO(((unsigned char *)&d->ccb.csio.sense_data));
-    struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-    debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                senset->error_code & SSD_ERRCODE,
-                senset->flags & SSD_KEY,
-                senset->add_sense_code,
-                senset->add_sense_code_qual );
-
-    if( needToClose )
-        m_device->close();
-    m_device->usageUnlock();
+    if( !(ccb.ccb_h.status & CAM_AUTOSNS_VALID) )
+        kDebug() << "(K3b::Device::ScsiCommand) sense data is not available";
 
+    ret = sense_to_err(ccb.csio.sense_data);
+    if( ret == 0 )
+        ret = 1;
+    kDebug() << "(K3b::Device::ScsiCommand) transport failed: " << ret;
     return ret;
 }
