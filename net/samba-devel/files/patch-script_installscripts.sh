--- script/installscripts.sh.orig	Tue Mar  9 15:35:54 2004
+++ script/installscripts.sh	Tue Mar  9 15:36:38 2004
@@ -25,8 +25,7 @@
   p2=`basename $p`
   echo Installing $BINDIR/$p2
   if [ -f $BINDIR/$p2 ]; then
-    rm -f $BINDIR/$p2.old
-    mv $BINDIR/$p2 $BINDIR/$p2.old
+    rm -f $BINDIR/$p2 $BINDIR/$p2.old
   fi
   cp $p $BINDIR/
   chmod $INSTALLPERMS $BINDIR/$p2
