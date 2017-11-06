--- inptstrm.c.orig	1995-05-31 13:04:11 UTC
+++ inptstrm.c
@@ -1,4 +1,5 @@
 #include "main.h"
+extern int Interactive;
 /*************************************************************************
     MPEG Streams Kontrolle
 
@@ -310,6 +311,7 @@ unsigned int length;
     fclose (info_file);
     output_info_video (video_info);
 
+  if( Interactive )
     ask_continue ();
 }
 
@@ -565,6 +567,7 @@ unsigned int length;
     close_bit_stream_r (&audio_bs);
     fclose (info_file);
     output_info_audio (audio_info);
+  if( Interactive )
     ask_continue ();
 
 }
