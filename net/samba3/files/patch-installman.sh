--- script/installman.sh.orig	Fri Jan 18 21:59:14 2002
+++ script/installman.sh	Fri Jan 18 21:59:40 2002
@@ -22,7 +22,7 @@
 	echo Installing \"$lang\" man pages in $MANDIR/lang/$lang
     fi
 
-    langdir=$MANDIR/lang/$lang
+    langdir=$MANDIR
     for d in $MANDIR $MANDIR/lang $langdir $langdir/man1 $langdir/man5 $langdir/man7 $langdir/man8; do
 	if [ ! -d $d ]; then
 	    mkdir $d
