--- libk3bdevice/k3bdevice.h.orig	2010-07-30 06:33:55.000000000 +0200
+++ libk3bdevice/k3bdevice.h	2010-07-30 06:35:35.000000000 +0200
@@ -222,6 +222,11 @@
              */
             QString blockDeviceName() const;
 
+            /**
+             * SCSI device path (bus_id:target_id:lun_id)
+             */
+            QString genericDeviceName() const;
+
             int maxWriteSpeed() const;
 
             /**
