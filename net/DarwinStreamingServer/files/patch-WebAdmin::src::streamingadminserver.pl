--- WebAdmin/src/streamingadminserver.pl.orig	Tue Oct 28 09:43:24 2003
+++ WebAdmin/src/streamingadminserver.pl	Sun Jan 18 07:25:04 2004
@@ -255,7 +255,7 @@ else {
 	  "gbrowse", "0",
 	  "ssl", "0",
 	  "crtfile", "/etc/streaming/streamingadminserver.pem",
-	  "keyfile", "/etc/streaming/streamingadminserver.pem",
+	  "keyfile", "/etc/streaming/streamingadminserver.key",
 	  #"keypasswordfile", "",
 	  "qtssQTPasswd", "/usr/local/bin/qtpasswd",
 	  "qtssPlaylistBroadcaster", "/usr/local/bin/PlaylistBroadcaster",
