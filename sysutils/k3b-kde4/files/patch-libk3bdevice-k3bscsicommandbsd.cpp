commit d8f73a5f66c6bbebac52a8b784affb106b188279
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Fri Oct 28 00:16:58 2011 -0200

    k3bscsicommand_bsd: Do not access the scsi_sense_data fields manually.
    
    cam users are expected to retrieve those values with scsi_extract_sense
    (or, since FreeBSD 9, scsi_extract_sense_len).
    
    FreeBSD 9 has changed the scsi_sense_data struct, but everything works
    fine in all supported releases if we just use scsi_extract_sense.
    
    CCMAIL: michalm@jabster.pl

diff --git a/libk3bdevice/k3bscsicommand_bsd.cpp b/libk3bdevice/k3bscsicommand_bsd.cpp
index ce6508e..52eda04 100644
--- ./libk3bdevice/k3bscsicommand_bsd.cpp
+++ ./libk3bdevice/k3bscsicommand_bsd.cpp
@@ -103,16 +103,16 @@ int K3b::Device::ScsiCommand::transport( TransportDirection dir,
         m_device->usageUnlock();
 
         struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-        debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                    senset->error_code & SSD_ERRCODE,
-                    senset->flags & SSD_KEY,
-                    senset->add_sense_code,
-                    senset->add_sense_code_qual );
+        int errorCode, senseKey, addSenseCode, addSenseCodeQual;
+        scsi_extract_sense( senset, &errorCode, &senseKey, &addSenseCode,
+                            &addSenseCodeQual );
+        debugError( d->ccb.csio.cdb_io.cdb_bytes[0], errorCode, senseKey,
+                    addSenseCode, addSenseCodeQual );
 
-        int result = (((senset->error_code & SSD_ERRCODE)<<24) & 0xF000 |
-                      ((senset->flags & SSD_KEY)<<16)          & 0x0F00 |
-                      (senset->add_sense_code<<8)              & 0x00F0 |
-                      (senset->add_sense_code_qual)            & 0x000F );
+        int result = ((errorCode<<24)    & 0xF000 |
+                      (senseKey<<16)     & 0x0F00 |
+                      (addSenseCode<<8)  & 0x00F0 |
+                      (addSenseCodeQual) & 0x000F );
 
         return result ? result : ret;
     }
@@ -152,11 +152,11 @@ int K3b::Device::ScsiCommand::transport( TransportDirection dir,
             kDebug() << "(K3b::Device::ScsiCommand) transport failed (2): " << ret;
             ret = -1;
             struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-            debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                        senset->error_code & SSD_ERRCODE,
-                        senset->flags & SSD_KEY,
-                        senset->add_sense_code,
-                        senset->add_sense_code_qual );
+            int errorCode, senseKey, addSenseCode, addSenseCodeQual;
+            scsi_extract_sense( senset, &errorCode, &senseKey, &addSenseCode,
+                                &addSenseCodeQual );
+            debugError( d->ccb.csio.cdb_io.cdb_bytes[0], errorCode, senseKey,
+                        addSenseCode, addSenseCodeQual );
 
             if( needToClose )
                 m_device->close();
@@ -170,11 +170,11 @@ int K3b::Device::ScsiCommand::transport( TransportDirection dir,
             errno=EIO,-1;
             ret = -1;
             struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-            debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                        senset->error_code & SSD_ERRCODE,
-                        senset->flags & SSD_KEY,
-                        senset->add_sense_code,
-                        senset->add_sense_code_qual );
+            int errorCode, senseKey, addSenseCode, addSenseCodeQual;
+            scsi_extract_sense( senset, &errorCode, &senseKey, &addSenseCode,
+                                &addSenseCodeQual );
+            debugError( d->ccb.csio.cdb_io.cdb_bytes[0], errorCode, senseKey,
+                        addSenseCode, addSenseCodeQual );
 
             if( needToClose )
                 m_device->close();
@@ -193,11 +193,11 @@ int K3b::Device::ScsiCommand::transport( TransportDirection dir,
     else
         CREAM_ON_ERRNO(((unsigned char *)&d->ccb.csio.sense_data));
     struct scsi_sense_data* senset = (struct scsi_sense_data*)sense;
-    debugError( d->ccb.csio.cdb_io.cdb_bytes[0],
-                senset->error_code & SSD_ERRCODE,
-                senset->flags & SSD_KEY,
-                senset->add_sense_code,
-                senset->add_sense_code_qual );
+    int errorCode, senseKey, addSenseCode, addSenseCodeQual;
+    scsi_extract_sense( senset, &errorCode, &senseKey, &addSenseCode,
+                        &addSenseCodeQual );
+    debugError( d->ccb.csio.cdb_io.cdb_bytes[0], errorCode, senseKey,
+                addSenseCode, addSenseCodeQual );
 
     if( needToClose )
         m_device->close();
