--- WebAdmin/src/streamingadminserver.pl.orig	Wed Apr 24 09:22:15 2002
+++ WebAdmin/src/streamingadminserver.pl	Mon Sep 30 02:48:53 2002
@@ -43,7 +43,7 @@
 }
 else
 {
-    eval "use Net::SSleay";
+    eval "use Net::SSLeay";
 }
 $ssl_available = 0;
 if (!$@) {
@@ -241,7 +241,7 @@
 	  "gbrowse", "0",
 	  "ssl", "0",
 	  "crtfile", "/etc/streaming/streamingadminserver.pem",
-	  "keyfile", "/etc/streaming/streamingadminserver.pem",
+	  "keyfile", "/etc/streaming/streamingadminserver.key",
 	  #"keypasswordfile", "",
 	  "qtssQTPasswd", "/usr/local/bin/qtpasswd",
 	  "qtssPlaylistBroadcaster", "/usr/local/bin/PlaylistBroadcaster",
@@ -249,7 +249,7 @@
 	  "helpurl", "http://helpqt.apple.com/dssWebAdminHelpR3/dssWebAdmin.help/DSSHelp.htm",
 	  "qtssAdmin", "streamingadmin",
 	  "cacheMessageFiles", "0",
-	  #"pidfile", "/var/streaming/streamingadminserver.pid"
+	  "pidfile", "/var/run/streamingadminserver.pid"
 	  );
 }
 
