--- src/global.c.orig	Sat Jul  3 19:19:19 2004
+++ src/global.c	Thu Jul 22 14:03:01 2004
@@ -3588,7 +3588,7 @@
   global.allowed_ports = NULL;
 
   global.auto_save = NULL;
-  global.ping_command = g_strdup("/bin/ping -c 3 $IP");
+  global.ping_command = g_strdup("/sbin/ping -c 3 $IP");
 
   global.browse_width[0] = 369;
   global.browse_width[1] = 80;
