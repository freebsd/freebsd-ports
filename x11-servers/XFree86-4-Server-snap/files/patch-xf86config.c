--- programs/Xserver/hw/xfree86/xf86config/xf86config.c.orig	Sat Oct 27 20:34:09 2001
+++ programs/Xserver/hw/xfree86/xf86config/xf86config.c	Sat Jun  8 11:35:18 2002
@@ -382,7 +382,7 @@
 
 static char *mousetype_name[] = {
 	"Microsoft compatible (2-button protocol)",
-	"Mouse Systems (3-button protocol)",
+	"Mouse Systems (3-button protocol) & FreeBSD moused protocol",
 	"Bus Mouse",
 	"PS/2 Mouse",
 	"Logitech Mouse (serial, old type, Logitech protocol)",
@@ -401,6 +401,9 @@
 #ifdef WSCONS_SUPPORT
 "On systems with wscons, the default is /dev/wsmouse.\n"
 #endif
+#ifdef __FreeBSD__
+"On FreeBSD, the default is /dev/sysmouse.\n"
+#endif
 "\n";
 
 static char *mousecomment_text =
@@ -544,10 +547,12 @@
 	printf("Mouse device: ");
 	getstring(s);
 	if (strlen(s) == 0)
-#ifndef WSCONS_SUPPORT
-		config_pointerdevice = "/dev/mouse";
-#else
+#ifdef WSCONS_SUPPORT
 		config_pointerdevice = "/dev/wsmouse";
+#elif defined(__FreeBSD__)
+		config_pointerdevice = "/dev/sysmouse";
+#else
+		config_pointerdevice = "/dev/mouse";
 #endif
 	else {
 		config_pointerdevice = Malloc(strlen(s) + 1);
