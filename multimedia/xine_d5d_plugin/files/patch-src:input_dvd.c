--- src/input_dvd.c.orig	Tue Jul  9 06:44:02 2002
+++ src/input_dvd.c	Tue Aug  6 00:26:08 2002
@@ -33,7 +33,6 @@
 #include <string.h>
 #include <errno.h>
 
-#include <sys/mount.h>
 #include <sys/wait.h>
 
 #include <sys/poll.h>
@@ -1050,7 +1049,7 @@
   dvdnav_input_plugin_t *this;
   config_values_t *config = xine->config;
 
-  if (iface != 7) {
+  if (iface != 8) {
     printf("d5d input plugin doesn't support plugin API version %d.\n"
 	   "PLUGIN DISABLED.\n"
 	   "This means there's a version mismatch between xine and this input"
