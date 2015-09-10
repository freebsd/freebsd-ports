--- src/http.c.orig	2003-01-16 19:52:17 UTC
+++ src/http.c
@@ -1,8 +1,10 @@
-# include <glib.h>
-# include <fcntl.h>
-# include <sys/stat.h>
+# include <sys/param.h>
 # include <sys/types.h>
+# include <sys/stat.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
+# include <glib.h>
+# include <fcntl.h>
 # include <arpa/inet.h>
 # include <unistd.h>
 # include <errno.h>
@@ -17,9 +19,6 @@
 # define BUF_SIZ 16384
 # endif
 
-// not portable, apparently
-# include <sys/sendfile.h>
-
 GIOChannel *http_bind_socket( const char *ip, int port, int queue ) { 
     struct sockaddr_in addr;
     int fd, r, n = 1;
@@ -354,7 +353,7 @@ ssize_t http_sendfile ( http_request *h,
 	return -1;
     }
 
-    r = sendfile( out_fd, in_fd, &len, s.st_size );
+    r = sendfile(in_fd, out_fd, 0, s.st_size, NULL, &len, 0);
     if (r == -1) {
 	g_warning("http_sendfile send: %m");
 	return -1;
