--- script/installman.sh.orig	Wed Aug 21 09:33:36 2002
+++ script/installman.sh	Wed Aug 21 09:33:53 2002
@@ -22,7 +22,7 @@
 	echo Installing \"$lang\" man pages in $MANDIR/lang/$lang
     fi
 
-    langdir=$MANDIR/$lang
+    langdir=$MANDIR
     for d in $MANDIR $langdir $langdir/man1 $langdir/man5 $langdir/man7 $langdir/man8; do
 	if [ ! -d $d ]; then
 	    mkdir $d
