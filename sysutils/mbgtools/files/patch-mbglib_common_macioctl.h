--- mbglib/common/macioctl.h.orig	2024-01-02 18:05:57 UTC
+++ mbglib/common/macioctl.h
@@ -259,10 +259,12 @@ typedef struct
     memcpy( _piob, _pin, _size )
 
   #define _frc_iob_to_pout( _piob, _pout, _size ) \
-    copyout( _piob, _pout, _size )
+    if (copyout( _piob, _pout, _size ) != 0) \
+      goto err_inval
 
   #define _frc_iob_from_pin( _piob, _pin, _size ) \
-    copyin( _pin, _piob, _size )
+    if (copyin( _pin, _piob, _size ) != 0) \
+      goto err_inval
 
   #define _io_wait_pcps_sec_change( _pddev, _cmd, _type, _pout ) \
     goto err_inval
