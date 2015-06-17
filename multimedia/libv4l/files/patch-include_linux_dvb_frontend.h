--- include/linux/dvb/frontend.h.orig	2015-01-10 15:04:07.446370686 +0100
+++ include/linux/dvb/frontend.h	2015-01-10 15:05:20.367365809 +0100
@@ -549,7 +549,13 @@
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
