--- inptstrm.c.orig	Wed May 31 08:04:11 1995
+++ inptstrm.c	Mon Sep  4 18:17:45 2000
@@ -1,4 +1,5 @@
 #include "main.h"
+extern int Interactive;
 /*************************************************************************
     MPEG Streams Kontrolle
 
@@ -310,6 +311,7 @@
     fclose (info_file);
     output_info_video (video_info);
 
+  if( Interactive )
     ask_continue ();
 }
 
@@ -565,6 +567,7 @@
     close_bit_stream_r (&audio_bs);
     fclose (info_file);
     output_info_audio (audio_info);
+  if( Interactive )
     ask_continue ();
 
 }
