--- src/xitk/download.c.orig	Sat Feb 21 13:38:19 2004
+++ src/xitk/download.c	Sat Feb 21 13:39:43 2004
@@ -39,6 +39,14 @@
 extern gGui_t   *gGui;
 
 #ifdef HAVE_CURL
+
+#ifndef TRUE
+#define TRUE 1
+#endif
+#ifndef FALSE
+#define FALSE 0
+#endif
+
 static int progress_callback(void *userdata, 
 			     double dltotal, double dlnow, double ultotal, double ulnow) {
   download_t  *download = (download_t *) userdata;
