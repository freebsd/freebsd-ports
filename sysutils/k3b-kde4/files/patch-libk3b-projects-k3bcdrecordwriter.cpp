--- libk3b/projects/k3bcdrecordwriter.cpp.orig	2014-11-04 18:37:31 UTC
+++ libk3b/projects/k3bcdrecordwriter.cpp
@@ -228,7 +228,11 @@ bool K3b::CdrecordWriter::prepareProcess
         d->process << "gracetime=2";  // 2 is the lowest allowed value (Joerg, why do you do this to us?)
 
     // Again we assume the device to be set!
+#if defined(Q_OS_FREEBSD)
+    d->process << QString("dev=%1").arg(K3b::externalBinGenericDeviceParameter(burnDevice(), d->cdrecordBinObject));
+#else
     d->process << QString("dev=%1").arg(K3b::externalBinDeviceParameter(burnDevice(), d->cdrecordBinObject));
+#endif
 
     d->usedSpeedFactor = K3b::speedMultiplicatorForMediaType( d->burnedMediaType );
     d->usedSpeed = burnSpeed();
