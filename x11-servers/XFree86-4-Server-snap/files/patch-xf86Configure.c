--- programs/Xserver/hw/xfree86/common/xf86Configure.c.orig	Sat Jun  8 18:48:54 2002
+++ programs/Xserver/hw/xfree86/common/xf86Configure.c	Sat Jun  8 18:50:09 2002
@@ -79,6 +79,9 @@
 #elif defined(__QNXNTO__)
 static char *DFLT_MOUSE_PROTO = "OSMouse";
 static char *DFLT_MOUSE_DEV = "/dev/devi/mouse0";
+#elif defined(__FreeBSD__)
+static char *DFLT_MOUSE_DEV = "/dev/sysmouse";
+static char *DFLT_MOUSE_PROTO = "MouseSystems";
 #else
 static char *DFLT_MOUSE_DEV = "/dev/mouse";
 static char *DFLT_MOUSE_PROTO = "auto";
