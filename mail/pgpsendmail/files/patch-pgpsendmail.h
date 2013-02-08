--- pgpsendmail.h.orig	1994-12-03 12:23:34.000000000 +0900
+++ pgpsendmail.h	2012-10-24 15:35:51.000000000 +0900
@@ -34,8 +34,12 @@
 #define LINE_LENGTH 1024
 #define BUF_LEN 4096
 #ifndef SENDMAIL
+#ifdef __FreeBSD__
+#  define SENDMAIL "/usr/sbin/sendmail"
+#else
 #  define SENDMAIL "/usr/lib/sendmail.real"
 #endif
+#endif
 #define SECRING_SIZE_TYPE int
 
 #define CHECK_CAN_ENCRYPT 0
