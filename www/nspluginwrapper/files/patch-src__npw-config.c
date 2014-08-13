--- src/npw-config.c.orig	2011-06-30 23:18:57.000000000 -0400
+++ src/npw-config.c	2013-11-14 14:41:13.000000000 -0500
@@ -133,8 +133,9 @@
 #if defined(__FreeBSD__)
 	{
 	  static const char *freebsd_dirs[] = {
-		"/usr/X11R6/" LIB "/browser_plugins",
-		"/usr/X11R6/" LIB "/firefox/plugins",
+		"%%LOCALBASE%%/" LIB "/browser_plugins",
+		"%%LOCALBASE%%/" LIB "/firefox/plugins",
+		"%%LOCALBASE%%/" LIB "/seamonkey/plugins",
 	  };
 	  dirs = freebsd_dirs;
 	}
@@ -232,11 +233,12 @@
 	"/usr/lib32/nsbrowser/plugins",				// XXX how unfortunate
 	"/usr/lib64/nsbrowser/plugins",
 #if defined(__FreeBSD__)
-	"/usr/X11R6/lib/browser_plugins",
-	"/usr/X11R6/lib/firefox/plugins",
-	"/usr/X11R6/lib/linux-mozilla/plugins",
-	"/usr/local/lib/npapi/linux-flashplugin",
-	"/usr/X11R6/Adobe/Acrobat7.0/ENU/Browser/intellinux",
+	"%%LOCALBASE%%/lib/browser_plugins",
+	"%%LOCALBASE%%/lib/firefox/plugins",
+	"%%LOCALBASE%%/lib/seamonkey/plugins",
+	"%%LOCALBASE%%/lib/browser_plugins/linux-f10-flashplugin",
+	"%%LOCALBASE%%/Adobe/Reader8/ENU/Adobe/Reader8/Browser/intellinux",
+	"%%LOCALBASE%%/Adobe/Reader9/ENU/Adobe/Reader9/Browser/intellinux",
 #endif
 #if defined(__DragonFly__)
 	"/usr/pkg/lib/netscape/plugins",
