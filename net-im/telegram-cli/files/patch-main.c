--- main.c.orig	2014-09-24 06:35:27.000000000 -0400
+++ main.c	2014-11-18 10:30:56.677155518 -0500
@@ -29,6 +29,10 @@
 #include <termios.h>
 #include <unistd.h>
 #include <assert.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
 #if (READLINE == GNU)
 #include <readline/readline.h>
 #else
@@ -803,7 +807,7 @@
   running_for_first_time ();
   parse_config ();
 
-  tgl_set_rsa_key ("/etc/" PROG_NAME "/server.pub");
+  tgl_set_rsa_key ("%%LOCALBASE%%/etc/" PROG_NAME "/server.pub");
   tgl_set_rsa_key ("tg-server.pub");
 
 
