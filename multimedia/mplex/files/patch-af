--- main.c.orig	Wed Apr  5 03:51:53 1995
+++ main.c	Mon Sep  4 18:17:45 2000
@@ -59,6 +59,7 @@
 *************************************************************************/
 
 #include "main.h"
+#include <unistd.h>
 
 /*************************************************************************
     Main
@@ -75,6 +76,8 @@
     struct timeval  tp_global_end;
 #endif
 
+int Interactive=0;
+
 int main (argc, argv)
 
 int argc;
@@ -93,6 +96,14 @@
     unsigned int which_streams=0;
     double	startup_delay=0;
 
+    int tmp;
+
+    if( getopt( argc, argv, "i" ) == 'i' )
+      Interactive=1;
+
+    optind -= 1;
+    argc -= optind;
+    argv += optind;
 
     intro (argc);
     check_files (argc, argv, &audio_file, &video_file, &multi_file,
