--- src/npw-config.c.orig	2011-07-01 03:18:57 UTC
+++ src/npw-config.c
@@ -133,8 +133,9 @@ static const char *get_system_mozilla_pl
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
@@ -232,11 +233,13 @@ static const char **get_mozilla_plugin_d
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
+	"%%LOCALBASE%%/lib/browser_plugins/linux-flashplayer",
+	"%%LOCALBASE%%/lib/browser_plugins/symlinks/linux-firefox",
+	"%%LOCALBASE%%/Adobe/Reader8/ENU/Adobe/Reader8/Browser/intellinux",
+	"%%LOCALBASE%%/Adobe/Reader9/ENU/Adobe/Reader9/Browser/intellinux",
 #endif
 #if defined(__DragonFly__)
 	"/usr/pkg/lib/netscape/plugins",
