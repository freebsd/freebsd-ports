--- src/tovid.sh.orig	Tue Dec 27 03:29:42 2005
+++ src/tovid.sh	Tue Dec 27 03:43:52 2005
@@ -1327,7 +1327,7 @@
         AUDIO_CMD="cat /dev/zero | $PRIORITY sox -t raw -c 2 -r $SAMPRATE -w -s - -t wav $AUDIO_WAV trim 0 $V_DURATION"
     # Extract audio normally
     else
-        AUDIO_CMD="$PRIORITY mplayer $MPLAYER_OPTS -quiet -vc null -vo null -ao pcm:waveheader:file=$AUDIO_WAV \"$IN_FILE\""
+        AUDIO_CMD="$PRIORITY mplayer $MPLAYER_OPTS -quiet -vc dummy -vo null -ao pcm:waveheader:file=$AUDIO_WAV \"$IN_FILE\""
         # Normalize, if requested
         if $DO_NORM; then
             AUDIO_CMD="$AUDIO_CMD -af volnorm"
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
