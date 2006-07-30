--- src/tovid.sh.orig	Tue Dec 27 03:29:42 2005
+++ src/tovid.sh	Tue Dec 27 03:43:52 2005
@@ -265,7 +265,7 @@
 check_disk_space()
 {
     # Determine space available in current directory (in MB)
-    AVAIL_SPACE=`df -mP . | awk 'NR != 1 {print $4;}'`
+    AVAIL_SPACE=`df -m . | awk 'NR != 1 {print $4;}'`
     # Rough estimates of KB/sec for different formats
     K_PER_SEC=200
     test x"$TGT_RES" = x"VCD" && K_PER_SEC=172
@@ -1512,8 +1512,8 @@
 # ******************************************************************************
 # ******************************************************************************
 
-AUDIO_SIZE=`du -c -b "$OUT_PREFIX.$AUD_SUF" | awk 'END{print $1}'`
-VIDEO_SIZE=`du -c -b "$OUT_PREFIX.$VID_SUF" | awk 'END{print $1}'`
+AUDIO_SIZE=`ls -ALln "$OUT_PREFIX.$AUD_SUF" | awk '{ sum += $5 } END { print sum }'`
+VIDEO_SIZE=`ls -ALln "$OUT_PREFIX.$VID_SUF" | awk '{ sum += $5 } END { print sum }'`
 # Total size of streams so far (in MBytes)
 TOTAL_SIZE=`expr \( $AUDIO_SIZE \+ $VIDEO_SIZE \) \/ 1000000`
 # If it will exceed disc size, add '%d' field to allow mplex to split the output
