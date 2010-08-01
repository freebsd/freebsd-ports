--- libk3b/projects/k3bcdrecordwriter.cpp.orig	2010-06-06 20:49:38.000000000 +0200
+++ libk3b/projects/k3bcdrecordwriter.cpp	2010-07-30 06:43:53.000000000 +0200
@@ -228,7 +228,11 @@
         d->process << "gracetime=2";  // 2 is the lowest allowed value (Joerg, why do you do this to us?)
 
     // Again we assume the device to be set!
+#if defined(Q_OS_FREEBSD)
+    d->process << QString("dev=%1").arg(K3b::externalBinGenericDeviceParameter(burnDevice(), d->cdrecordBinObject));
+#else
     d->process << QString("dev=%1").arg(K3b::externalBinDeviceParameter(burnDevice(), d->cdrecordBinObject));
+#endif
 
     d->usedSpeedFactor = K3b::speedMultiplicatorForMediaType( d->burnedMediaType );
     d->usedSpeed = burnSpeed();
