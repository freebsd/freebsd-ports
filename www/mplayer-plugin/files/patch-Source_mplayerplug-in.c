--- Source/mplayerplug-in.c.orig	Thu May 22 22:38:28 2003
+++ Source/mplayerplug-in.c	Mon Jul 21 15:14:24 2003
@@ -142,9 +142,6 @@
 		"audio/mpeg3:mp3:MPEG audio;"
 		"audio/x-mpeg3:mp3:MPEG audio;"
 		"audio/mp3:mp3:MPEG audio;"
-		"audio/x-pn-realaudio:ram:RealAudio;"
-		"audio/x-pn-realaudio-plugin:rpm:RealAudio;"
-		"audio/x-realaudio:ra:RealAudio;"
 		"video/fli:fli,flc:FLI animation;"
 		"video/x-fli:fli,flc:FLI animation;"
 		"video/x-ms-asf-plugin:asf,asx:Windows Media;"
@@ -262,7 +262,7 @@
 	}
 
 	if (config == NULL) {
-		config = fopen("/etc/mplayerplug-in.conf","r");
+		config = fopen("%%PREFIX%%/etc/mplayerplug-in.conf","r");
 	}
 
 	DEBUG = 0;
