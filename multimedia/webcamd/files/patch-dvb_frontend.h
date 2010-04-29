--- v4l-dvb/linux/include/linux/dvb/frontend.h.orig	2010-03-19 03:47:27.000000000 +0100
+++ v4l-dvb/linux/include/linux/dvb/frontend.h	2010-04-15 13:00:04.000000000 +0200
@@ -373,7 +373,7 @@
 };
 
 #define FE_SET_PROPERTY		   _IOW('o', 82, struct dtv_properties)
-#define FE_GET_PROPERTY		   _IOR('o', 83, struct dtv_properties)
+#define FE_GET_PROPERTY		   _IOW('o', 83, struct dtv_properties)
 
 
 /**
