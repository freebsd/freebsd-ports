--- scripts/exports/ffmpeg_dvd.sh.orig	Tue Apr  6 06:24:33 2004
+++ scripts/exports/ffmpeg_dvd.sh	Sun Apr 11 02:58:11 2004
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-function usage
+usage()
 {
 	# Title
 	echo "Title: FFMPEG DVD-Video Export"
@@ -22,7 +22,7 @@
 	fi
 }
 
-function execute
+execute()
 {
 	# Arguments
 	normalisation="$1"
