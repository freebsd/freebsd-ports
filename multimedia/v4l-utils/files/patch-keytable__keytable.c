--- ./keytable/keytable.c.orig	2011-02-09 23:04:27.000000000 +0100
+++ ./keytable/keytable.c	2011-06-03 19:08:13.000000000 +0200
@@ -28,7 +28,11 @@
 #include "parse.h"
 
 /* Default place where the keymaps will be stored */
+#ifndef __FreeBSD__
 #define CFGDIR "/etc/rc_keymaps"
+#else
+#define CFGDIR PREFIX "/etc/rc_keymaps"
+#endif
 
 struct input_keymap_entry_v2 {
 #define KEYMAP_BY_INDEX	(1 << 0)
@@ -137,6 +141,10 @@
 	"--sysdev [ir class (f. ex. rc0)]\n"
 	"[for using the rc0 sysdev]";
 
+#ifdef __FreeBSD__
+#define devname dev_name
+#endif
+
 /* Static vars to store the parameters */
 static char *devclass = "rc0";
 static char *devname = NULL;
