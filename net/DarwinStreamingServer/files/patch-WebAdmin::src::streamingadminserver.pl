--- WebAdmin/src/streamingadminserver.pl.orig	Thu Aug 28 08:21:55 2003
+++ WebAdmin/src/streamingadminserver.pl	Sat Jan 22 09:55:56 2005
@@ -40,7 +40,7 @@
 }
 else
 {
-    eval "use Net::SSleay";
+    eval "use Net::SSLeay";
 }
 $ssl_available = 0;
 if (!$@) {
@@ -248,7 +248,7 @@
 	  "gbrowse", "0",
 	  "ssl", "0",
 	  "crtfile", "/etc/streaming/streamingadminserver.pem",
-	  "keyfile", "/etc/streaming/streamingadminserver.pem",
+	  "keyfile", "/etc/streaming/streamingadminserver.key",
 	  #"keypasswordfile", "",
 	  "qtssQTPasswd", "/usr/local/bin/qtpasswd",
 	  "qtssPlaylistBroadcaster", "/usr/local/bin/PlaylistBroadcaster",
