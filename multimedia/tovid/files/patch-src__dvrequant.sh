--- src/dvrequant.sh.orig	Fri Jan 20 00:23:01 2006
+++ src/dvrequant.sh	Fri Jan 20 00:26:34 2006
@@ -446,11 +446,11 @@
 echo "You may consult the log file:$PROCESS_LOG"
 echo " "
 echo "BURNING:"
-echo "Use to burn image: growisofs -dvd-compat -Z $DVD_DEVICE=$DISK_TITLE.iso "
+echo "Use to burn image: growisofs -dvd-compat -dvd-video -use-the-force-luke=dao -Z $DVD_DEVICE=$DISK_TITLE.iso "
 echo "Insert blank dvd and press ENTER"
 read BURN
 cd $WORKING_DIR/$DISK_TITLE
-growisofs -dvd-compat -Z $DVD_DEVICE=$DISK_TITLE.iso 
+growisofs -dvd-compat -dvd-video -use-the-force-luke=dao -Z $DVD_DEVICE=$DISK_TITLE.iso 
 
 exit
 
