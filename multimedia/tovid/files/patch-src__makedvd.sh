--- src/makedvd.sh.orig	Fri Jan 20 00:23:04 2006
+++ src/makedvd.sh	Fri Jan 20 00:27:46 2006
@@ -236,7 +236,7 @@
     
 # Burn the disc, if requested
 if $DO_BURN; then
-    BURN_CMD="growisofs -dvd-compat -speed=$BURN_SPEED -Z $DVDRW_DEVICE=$DISC_LABEL.iso"
+    BURN_CMD="growisofs -dvd-compat -dvd-video -use-the-force-luke=dao -speed=$BURN_SPEED -Z $DVDRW_DEVICE=$DISC_LABEL.iso"
     echo $SEPARATOR
     echo "Burning ISO to DVD with the following command:"
     echo $BURN_CMD
