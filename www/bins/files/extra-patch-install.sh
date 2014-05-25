--- install.sh.orig	2014-05-20 08:56:00.000000000 -0700
+++ install.sh	2014-05-20 09:00:43.000000000 -0700
@@ -24,6 +24,7 @@
 GLOBAL_RC="$RC"
 
 DESTDIR=`echo "$DESTDIR"|sed 's%/$%%'`
+ORIGPREFIX=$PREFIX
 PREFIX=$DESTDIR/`echo "$PREFIX"|sed 's%^/%%'`
 PREFIX=`echo "$PREFIX"|sed 's%/$%%'`
 ETC=$DESTDIR/`echo "$ETC"|sed 's%^/%%'`
@@ -35,7 +36,7 @@
 SHARE="$PREFIX/share"
 DATA="$SHARE/bins"
 GLADE="$DATA"
-LOCALE="$SHARE/locale"
+LOCALE="${SHARE}/locale"
 MAN="$PREFIX/man/man1"
 
 cd `dirname $0`
@@ -67,11 +68,10 @@
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
@@ -169,13 +169,6 @@
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
@@ -203,9 +196,6 @@
   do
     mkdir -p $LOCALE/$L/LC_MESSAGES 2>/dev/null || true
     cp intl/$L.mo $LOCALE/$L/LC_MESSAGES/bins.mo
-    if [ -f intl/gui-$L.mo ]; then
-      cp intl/gui-$L.mo $LOCALE/$L/LC_MESSAGES/bins-edit-gui.mo
-    fi
   done
 else
   cat <<!EoF  
@@ -227,7 +217,7 @@
 do
   echo -n " $FILE"
   ed "$FILE" <<EoF 2>/dev/null
-1,\$s%/usr/local/share%$SHARE%g
+1,\$s%/usr/local/share%$ORIGPREFIX/share%g
 1,\$s%/etc/bins%$GLOBAL_RC%g
 wq
 EoF
