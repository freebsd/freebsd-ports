--- programs/Xserver/hw/xfree86/xf86cfg/text-mode.c.orig	Wed Oct 31 14:50:30 2001
+++ programs/Xserver/hw/xfree86/xf86cfg/text-mode.c	Fri Jun  7 15:47:18 2002
@@ -498,6 +498,8 @@
     if (str == NULL)
 #ifdef WSCONS_SUPPORT
 	str = "/dev/wsmouse";
+#elif defined(__FreeBSD__)
+	str = "/dev/sysmouse";
 #else
 	str = "/dev/mouse";
 #endif
