--- beep/mainwin.c.orig	Fri May 13 17:18:27 2005
+++ beep/mainwin.c	Fri May 13 17:19:56 2005
@@ -441,13 +441,13 @@
                            gint * n_channels)
 {
     if (bitrate)
-        playback_info.bitrate = *bitrate;
-
+	*bitrate = playback_info.bitrate;
+	    
     if (frequency)
-        playback_info.frequency = *frequency;
-
+	*frequency = playback_info.frequency;
+	    
     if (n_channels)
-        playback_info.n_channels = *n_channels;
+	*n_channels = playback_info.n_channels;
 }
 
 static void
