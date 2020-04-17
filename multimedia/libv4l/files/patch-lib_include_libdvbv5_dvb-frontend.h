--- lib/include/libdvbv5/dvb-frontend.h.orig	2020-04-09 16:29:54 UTC
+++ lib/include/libdvbv5/dvb-frontend.h
@@ -908,7 +908,17 @@ struct dtv_properties {
 #define FE_DISHNETWORK_SEND_LEGACY_CMD _IO('o', 80) /* unsigned int */
 
 #define FE_SET_PROPERTY		   _IOW('o', 82, struct dtv_properties)
+#ifdef __linux__
 #define FE_GET_PROPERTY		   _IOR('o', 83, struct dtv_properties)
+#else
+/*
+ * This is broken on Linux as well but they workaround it in the driver.
+ * Since this is impossible to do on FreeBSD fix the header instead.
+ * Detailed and discussion :
+ * http://lists.freebsd.org/pipermail/freebsd-multimedia/2010-April/010958.html
+ */
+#define FE_GET_PROPERTY		   _IOW('o', 83, struct dtv_properties)
+#endif
 
 
 /*
