--- kopete/libkopete/avdevice/videodevicepool.cpp	2009-01-06 19:45:59.000000000 +0100
+++ kopete/libkopete/avdevice/videodevicepool.cpp	2009-01-06 19:47:13.000000000 +0100
@@ -608,7 +608,7 @@
     /// @todo implement me
 
 	kdDebug(14010) <<  k_funcinfo << "called" << endl;
-#if defined(__linux__) && defined(ENABLE_AV)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(ENABLE_AV)	
 	QDir videodevice_dir;
 	const QString videodevice_dir_path=QString::fromLocal8Bit("/dev/v4l/");
 	const QString videodevice_dir_filter=QString::fromLocal8Bit("video*");

