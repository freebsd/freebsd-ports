--- install.sh.orig	Sat Nov 23 09:40:01 2002
+++ install.sh	Sat Nov 23 09:40:58 2002
@@ -60,12 +60,11 @@
   mkdir -p $BIN 2>/dev/null || true
   if [ -w $BIN ] ; then
     echo "Installing program files in $BIN"
-    cp bins bins_edit bins-edit-gui $BIN
+    cp bins bins_edit $BIN
     chmod a+rx $BIN/bins
     chmod a+rx $BIN/bins_edit
-    chmod a+rx $BIN/bins-edit-gui
     perl -pi -e "s{/usr/local/share}{$SHARE}g" \
-     $BIN/bins $BIN/bins_edit $BIN/bins-edit-gui
+     $BIN/bins $BIN/bins_edit
     return 0
   else
     echo "Cannot write to $BIN directory." 
@@ -124,13 +123,6 @@
   fi
 fi
 
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
@@ -146,9 +138,6 @@
   do
     mkdir -p $LOCALE/$L/LC_MESSAGES 2>/dev/null || true
     cp intl/$L.mo $LOCALE/$L/LC_MESSAGES/bins.mo
-    if [ -f intl/gui-$L.mo ]; then
-      cp intl/gui-$L.mo $LOCALE/$L/LC_MESSAGES/bins-edit-gui.mo
-    fi
   done
 else
   cat <<!EoF
