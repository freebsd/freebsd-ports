--- libk3b/core/k3bglobals.cpp.orig	2014-11-04 18:37:31 UTC
+++ libk3b/core/k3bglobals.cpp
@@ -322,6 +322,13 @@ QString K3b::externalBinDeviceParameter(
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
