--- main.c.orig	2014-09-24 12:35:27.000000000 +0200
+++ main.c	2014-10-02 10:22:46.000000000 +0200
@@ -59,6 +59,7 @@
 
 #include <grp.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #include "telegram.h"
 #include "loop.h"
@@ -803,7 +804,7 @@
   running_for_first_time ();
   parse_config ();
 
-  tgl_set_rsa_key ("/etc/" PROG_NAME "/server.pub");
+  tgl_set_rsa_key ("%%PREFIX%%/etc/tg-server.pub");
   tgl_set_rsa_key ("tg-server.pub");
 
 
