--- dvb/frontend.h.orig	2010-04-15 11:20:34.000000000 +0200
+++ dvb/frontend.h	2010-04-15 11:21:23.000000000 +0200
@@ -373,7 +373,7 @@
 };
 
 #define FE_SET_PROPERTY		   _IOW('o', 82, struct dtv_properties)
-#define FE_GET_PROPERTY		   _IOR('o', 83, struct dtv_properties)
+#define FE_GET_PROPERTY		   _IOW('o', 83, struct dtv_properties)
 
 
 /**
