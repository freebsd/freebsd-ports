--- libclamav/pst.c.orig	Thu Apr 27 07:31:06 2006
+++ libclamav/pst.c	Thu Apr 27 07:36:10 2006
@@ -57,6 +57,10 @@
 
 #define DEBUG_VERSION 1
 
+#if (__FreeBSD_version < 500000)
+#define INT32_MAX 0x7fffffff
+#endif
+
 #if WORDS_BIGENDIAN == 0
 /*
  * don't use le??_to_host because they generate a huge number of statement with
