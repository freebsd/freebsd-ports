--- etc/mhn.defaults.sh.orig	Tue Apr 11 18:25:23 2000
+++ etc/mhn.defaults.sh	Tue Nov 28 13:44:27 2006
@@ -111,16 +111,6 @@
 	echo "mhshow-show-video/mpeg: %p$PGM '%f'" >> $TMP
 fi
 
-PGM="`$SEARCHPROG $SEARCHPATH lpr`"
-if [ ! -z "$PGM" ]; then
-	echo "mhshow-show-application/PostScript: %plpr -Pps" >> $TMP
-else
-    PGM="`$SEARCHPROG $SEARCHPATH lp`"
-    if [ ! -z "$PGM" ]; then    
-	echo "mhshow-show-application/PostScript: %plp -dps" >> $TMP
-    fi
-fi
-
 PGM="`$SEARCHPROG $SEARCHPATH ivs_replay`"
 if [ ! -z "$PGM" ]; then
 	echo "mhshow-show-application/x-ivs: %p$PGM -o '%F'" >> $TMP
