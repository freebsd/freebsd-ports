--- src/config.h.orig	Fri May 18 14:06:47 2001
+++ src/config.h	Thu Nov 29 16:26:26 2001
@@ -11,16 +11,19 @@
 /* define below if you're on a big endian architecture */
 /* #define WORDS_BIGENDIAN */
 
+/*FreeBSD dev driver*/
+#define USE_FREEBSD_SYSCTL
+
 /* linux /proc/net/dev driver */
 /* #define USE_LINUX_PROC */
 
 /* free pppd for Solaris 2.x and compatible streams ppp devices */
-#define USE_SOLARIS_FPPPD
+//#define USE_SOLARIS_FPPPD
 
 /* solaris kstat driver, also works on kstat compatible OSs */
-#define USE_SOLARIS_KSTAT
+//#define USE_SOLARIS_KSTAT
 
 /* dummy driver for testing purposes, it's safe to leave it defined */
-#define USE_TESTING_DUMMY
+//#define USE_TESTING_DUMMY
 
 #endif
