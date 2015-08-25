--- libk3bdevice/k3bdevice.h.orig	2014-11-04 18:37:31 UTC
+++ libk3bdevice/k3bdevice.h
@@ -222,6 +222,11 @@ namespace K3b {
              */
             QString blockDeviceName() const;
 
+            /**
+             * SCSI device path (bus_id:target_id:lun_id)
+             */
+            QString genericDeviceName() const;
+
             int maxWriteSpeed() const;
 
             /**
