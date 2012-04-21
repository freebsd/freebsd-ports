--- dvbdevice.h.orig
+++ dvbdevice.h
@@ -18,7 +18,7 @@
 #error VDR requires Linux DVB driver API version 5.3 or higher!
 #endif
 
-#define MAXDVBDEVICES  8
+#define MAXDVBDEVICES  63
 #define MAXDELIVERYSYSTEMS 8
 
 #define DEV_VIDEO         "/dev/video"
