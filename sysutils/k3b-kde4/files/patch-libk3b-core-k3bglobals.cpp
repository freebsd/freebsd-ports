--- libk3b/core/k3bglobals.cpp.orig	2010-07-30 06:36:01.794731453 +0000
+++ libk3b/core/k3bglobals.cpp	2010-07-30 06:37:34.104075238 +0000
@@ -321,6 +321,13 @@
 }
 
 
+QString K3b::externalBinGenericDeviceParameter( K3b::Device::Device* dev, const K3b::ExternalBin* bin )
+{
+    Q_UNUSED( bin );
+    return dev->genericDeviceName();
+}
+
+
 K3b::WritingApp K3b::writingAppFromString( const QString& s )
 {
     if( s.toLower() == "cdrdao" )
