--- src/global.c.orig	Sun Nov  4 13:30:19 2001
+++ src/global.c	Sat Jan 26 22:15:50 2002
@@ -1333,7 +1333,6 @@
   
   return NULL;
 }
-*/
 
 char *strcasestr(char *str, char *sub)
 {
@@ -1361,6 +1360,7 @@
 
   return NULL;
 }
+*/
 
 int idle_function(gpointer data ATTR_UNUSED)
 {
@@ -3597,7 +3597,7 @@
   global.auto_save = NULL;
   global.execs = NULL;
   global.pings = NULL;
-  global.ping_command = l_strdup("/bin/ping -c 3 $IP");
+  global.ping_command = l_strdup("/sbin/ping -c 3 $IP");
 
   global.browse_width[0] = 369;
   global.browse_width[1] = 80;
