--- libk3bdevice/k3bdevice.cpp.orig	2010-06-06 15:32:49.000000000 +0200
+++ libk3bdevice/k3bdevice.cpp	2010-07-30 06:44:02.000000000 +0200
@@ -309,6 +309,12 @@
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
@@ -363,6 +369,14 @@
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
