--- plugins/output_http/httpd.c.orig	2008-06-16 14:23:47.000000000 +0300
+++ plugins/output_http/httpd.c	2013-08-24 04:52:20.000000000 +0300
@@ -33,6 +33,8 @@
 #include <fcntl.h>
 #include <syslog.h>
 
+#include <netinet/in.h>
+
 #include "../../mjpg_streamer.h"
 #include "../../utils.h"
 #include "httpd.h"
