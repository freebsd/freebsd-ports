--- src/zm_monitor.cpp.orig	2018-10-13 18:36:15 UTC
+++ src/zm_monitor.cpp
@@ -2110,6 +2110,7 @@ Monitor *Monitor::Load(MYSQL_ROW dbrow, bool load_zone
   Camera *camera = 0;
   if ( type == "Local" ) {
 
+#if ZM_HAS_V4L
     int extras = (deinterlacing>>24)&0xff;
 
     camera = new LocalCamera(
@@ -2132,6 +2133,9 @@ Monitor *Monitor::Load(MYSQL_ROW dbrow, bool load_zone
         record_audio,
         extras
         );
+#else
+    Fatal("ZoneMinder not built with Local Camera support");
+#endif
   } else if ( type == "Remote" ) {
     if ( protocol == "http" ) {
       camera = new RemoteCameraHttp(
