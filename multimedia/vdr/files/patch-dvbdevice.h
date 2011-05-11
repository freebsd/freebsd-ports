--- dvbdevice.h.orig
+++ dvbdevice.h
@@ -19,7 +19,7 @@
 #error VDR requires Linux DVB driver API version 5.0 or higher!
 #endif
 
-#define MAXDVBDEVICES  8
+#define MAXDVBDEVICES  63
 
 #define DEV_VIDEO         "/dev/video"
 #define DEV_DVB_ADAPTER   "/dev/dvb/adapter"
