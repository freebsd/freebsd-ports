--- src/slint.c.orig	Fri Jan 24 08:13:03 2003
+++ src/slint.c	Fri Jan 24 08:13:44 2003
@@ -434,6 +434,11 @@
     "console",
 #endif
     "linux",
+#ifdef __FreeBSD__
+    "cons25",
+    "cons25r",
+    "xterm",
+#endif
     "xterm-color",
     "color-xterm",
     "dtterm",
