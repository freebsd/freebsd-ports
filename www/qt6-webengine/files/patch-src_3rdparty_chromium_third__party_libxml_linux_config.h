--- src/3rdparty/chromium/third_party/libxml/linux/config.h.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/third_party/libxml/linux/config.h
@@ -69,6 +69,9 @@
 /* Define to 1 if you have the <pthread.h> header file. */
 #define HAVE_PTHREAD_H /**/
 
+/* Define to 1 if you have the `arc4random' function. */
+#define HAVE_ARC4RANDOM 1
+
 /* Define to 1 if you have the `rand_r' function. */
 
 
