--- install.sh.orig	Thu Aug 25 06:07:05 2005
+++ install.sh	Mon Mar 19 02:47:24 2007
@@ -67,11 +67,10 @@
   if [ -w $BIN ] ; then
     echo "Installing program files in $BIN"
     # bins_cleanupgallery anti_bins
-    cp bins bins_edit bins-edit-gui $BIN
+    cp bins bins_edit $BIN
     chmod a+rx $BIN/bins
     chmod a+rx $BIN/bins_edit
     chmod a+rx $BIN/bins_cleanupgallery
-    chmod a+rx $BIN/bins-edit-gui
     chmod a+rx $BIN/anti_bins
 #    perl -pi -e "s{/usr/local/share}{$SHARE}g" \
 #     $BIN/bins $BIN/bins_edit $BIN/bins-edit-gui
@@ -169,13 +168,6 @@
 fi
 set -o errexit
 
-# additionnal files
-mkdir -p $GLADE 2>/dev/null || true
-if [ -w $GLADE ] ; then
-  echo "Installing additionnal files in $GLADE"
-  cp bins-edit-gui.glade $GLADE
-fi
-
 # man pages
 mkdir -p $MAN 2>/dev/null || true
 if [ -w $MAN ] ; then
@@ -203,9 +195,6 @@
   do
     mkdir -p $LOCALE/$L/LC_MESSAGES 2>/dev/null || true
     cp intl/$L.mo $LOCALE/$L/LC_MESSAGES/bins.mo
-    if [ -f intl/gui-$L.mo ]; then
-      cp intl/gui-$L.mo $LOCALE/$L/LC_MESSAGES/bins-edit-gui.mo
-    fi
   done
 else
   cat <<!EoF  
