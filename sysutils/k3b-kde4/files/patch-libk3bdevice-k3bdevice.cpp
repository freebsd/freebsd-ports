--- libk3bdevice/k3bdevice.cpp.orig	2014-11-04 18:37:31 UTC
+++ libk3bdevice/k3bdevice.cpp
@@ -322,6 +322,12 @@ QString K3b::Device::Device::blockDevice
 }
 
 
+QString K3b::Device::Device::genericDeviceName() const
+{
+    return d->genericDevice;
+}
+
+
 int K3b::Device::Device::maxWriteSpeed() const
 {
     return d->maxWriteSpeed;
@@ -376,6 +382,14 @@ bool K3b::Device::Device::init( bool bCh
     if( !open() )
         return false;
 
+#if defined(Q_OS_FREEBSD)
+    if( d->deviceHandle ) {
+        d->genericDevice = QString("%1").arg(d->deviceHandle->path_id)
+            + QString(",%1").arg(d->deviceHandle->target_id)
+            + QString(",%1").arg(d->deviceHandle->target_lun);
+    }
+#endif
+
     //
     // inquiry
     // use a 36 bytes buffer since not all devices return the full inquiry struct
