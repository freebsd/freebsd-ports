--- programs/Xserver/hw/xfree86/os-support/bus/Sbus.c.orig	Fri May 16 15:33:46 2003
+++ programs/Xserver/hw/xfree86/os-support/bus/Sbus.c	Fri May 16 15:37:46 2003
@@ -170,6 +170,8 @@
 	promP1275 = TRUE;
     else
 	promP1275 = FALSE;
+#elif defined(__FreeBSD__)
+    promP1275 = TRUE;
 #else
 #error Missing promIsP1275() function for this OS
 #endif
