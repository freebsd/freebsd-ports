--- ./lib/include/libdvbv5/dvb-frontend.h.orig	2016-09-13 19:57:29.863954000 +0200
+++ ./lib/include/libdvbv5/dvb-frontend.h	2016-09-13 19:58:07.703108000 +0200
@@ -553,7 +553,13 @@
 };
 
 #define FE_SET_PROPERTY		   _IOW('o', 82, struct dtv_properties)
-#define FE_GET_PROPERTY		   _IOR('o', 83, struct dtv_properties)
+/* 
+ * This is broken on linux as well but they workaround it in the driver.
+ * Since this is impossible to do on FreeBSD fix the header instead.
+ * Detailed and discussion :
+ * http://lists.freebsd.org/pipermail/freebsd-multimedia/2010-April/010958.html
+ */
+#define FE_GET_PROPERTY		   _IOW('o', 83, struct dtv_properties)
 
 
 /**
