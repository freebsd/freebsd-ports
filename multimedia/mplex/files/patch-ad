--- multplex.c.orig	Tue Jun  6 07:16:52 1995
+++ multplex.c	Mon Sep  4 18:17:45 2000
@@ -1,4 +1,5 @@
 #include "main.h"
+extern int Interactive;
 #ifdef TIMER
     extern long total_sec;
     extern long total_usec;
@@ -129,6 +130,7 @@
 	picture_start = TRUE;
     }
 
+if( Interactive ) {
 printf("\nMerging elementary streams to MPEG/SYSTEMS multiplexed stream.\n");
 printf("\n+------------------ MPEG/SYSTEMS INFORMATION -----------------+\n");
     
@@ -144,6 +146,12 @@
     scanf ("%ld", &video_buffer_size);
     printf   ("STD audio buffer in kB (CSPS: max  4 kB) : ");
     scanf ("%ld", &audio_buffer_size);
+} else {
+    sector_size=2324;
+    packets_per_pack=1;
+    video_buffer_size=46;
+    audio_buffer_size=4;
+}
 
     write_pack = packets_per_pack;
     video_buffer_size *= 1024;
@@ -197,6 +205,7 @@
 		 (double)(packets_per_pack-1.))) / (double)(packets_per_pack) );
     data_rate = ceil(dmux_rate/50.)*50;
 
+if( Interactive ) {
     printf ("\ncomputed multiplexed stream data rate    : %7.3f\n",dmux_rate);
     printf ("target data rate (e.g. %6u)           : ",data_rate);
     scanf  ("%lf", &dmux_rate);
@@ -206,12 +215,21 @@
     scanf  ("%u", &video_delay_ms);
     printf ("audio stream startup offset (ms)         : ");
     scanf  ("%u", &audio_delay_ms);
+} else {
+    dmux_rate=data_rate;
+    sectors_delay=8;
+    video_delay_ms=0;
+    audio_delay_ms=0;
+}
 
     video_delay = (double)video_delay_ms*(double)(CLOCKS/1000);
     audio_delay = (double)audio_delay_ms*(double)(CLOCKS/1000);
 
+if( Interactive ) {
     verbose=ask_verbose();
     printf ("\n");
+} else
+    verbose=1;
 
 #ifdef TIMER
     gettimeofday (&tp_global_start,NULL);
