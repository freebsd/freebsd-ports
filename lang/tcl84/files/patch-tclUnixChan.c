--- tclUnixChan.c.org	Wed Feb 25 16:54:52 2004
+++ tclUnixChan.c	Mon Jun 28 13:57:18 2004
@@ -1787,7 +1787,8 @@
     }
     fd = TclOSopen(native, mode, permissions);
 #ifdef SUPPORTS_TTY
-    ctl_tty = (strcmp (native, "/dev/tty") == 0);
+    ctl_tty = (strcmp (native, "/dev/tty") == 0) ||
+	    (strcmp (native, "/dev/cua") == 0);
 #endif /* SUPPORTS_TTY */
 
     if (fd < 0) {
