--- src/npw-config.c.orig	2011-04-23 14:47:21.000000000 -0400
+++ src/npw-config.c	2011-04-25 17:46:44.000000000 -0400
@@ -186,8 +186,9 @@
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
@@ -283,11 +284,13 @@
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
+	"%%LOCALBASE%%/lib/npapi/linux-flashplugin",
+	"%%LOCALBASE%%/lib/npapi/linux-f10-flashplugin",
+	"%%LOCALBASE%%/Adobe/Acrobat7.0/ENU/Browser/intellinux",
+	"%%LOCALBASE%%/Adobe/Reader8/ENU/Adobe/Reader8/Browser/intellinux",
 #endif
 #if defined(__DragonFly__)
 	"/usr/pkg/lib/netscape/plugins",
