--- libhttpd.h.orig	Sun Oct 20 23:50:43 2002
+++ libhttpd.h	Sun Oct 20 23:51:10 2002
@@ -141,6 +141,9 @@
     struct stat sb;
     int conn_fd;
     char* file_address;
+#ifdef USE_SENDFILE
+    int file_fd;
+#endif
     } httpd_conn;
 
 /* Methods. */
