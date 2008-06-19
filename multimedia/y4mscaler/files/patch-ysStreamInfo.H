--- ysStreamInfo.H.orig	2005-12-11 21:27:03.000000000 +0100
+++ ysStreamInfo.H	2008-04-21 18:39:02.844054735 +0200
@@ -24,6 +24,12 @@
 
 #include <string.h>
 
+/* XXX Obsolete as soon as v9.1 is out */
+#define LOG_DEBUG 1
+#define LOG_INFO 2
+#define LOG_WARN 3
+#define LOG_ERROR 4
+
 extern "C" {
 #include <yuv4mpeg.h>
 }
