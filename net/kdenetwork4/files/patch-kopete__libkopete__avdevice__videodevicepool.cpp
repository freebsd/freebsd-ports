--- ./kopete/libkopete/avdevice/videodevicepool.cpp.orig	2010-10-01 01:22:38.000000000 +0400
+++ ./kopete/libkopete/avdevice/videodevicepool.cpp	2010-10-31 23:13:07.588295799 +0300
@@ -557,7 +557,7 @@
 
 	if (m_videodevice.isEmpty()) {
 		kDebug() << "called";
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)
 		foreach (Solid::Device device,
 				Solid::Device::listFromType(Solid::DeviceInterface::Video, QString())) {
 			registerDevice( device );
