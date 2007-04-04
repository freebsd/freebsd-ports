--- ./src/npw-config.c.orig	Sun Mar  4 23:01:22 2007
+++ ./src/npw-config.c	Wed Apr  4 20:20:59 2007
@@ -119,8 +119,8 @@
 #if defined(__FreeBSD__)
 	{
 	  static const char *freebsd_dirs[] = {
-		"/usr/X11R6/" LIB "/browser_plugins",
-		"/usr/X11R6/" LIB "/firefox/plugins",
+		"/usr/local/" LIB "/browser_plugins",
+		"/usr/local/" LIB "/firefox/plugins",
 	  };
 	  dirs = freebsd_dirs;
 	}
