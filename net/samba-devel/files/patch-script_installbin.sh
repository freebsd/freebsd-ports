--- script/installbin.sh.orig	Tue Mar  9 15:33:32 2004
+++ script/installbin.sh	Tue Mar  9 15:35:43 2004
@@ -17,8 +17,7 @@
  p2=`basename $p`
  echo Installing $p as $BINDIR/$p2
  if [ -f $BINDIR/$p2 ]; then
-   rm -f $BINDIR/$p2.old
-   mv $BINDIR/$p2 $BINDIR/$p2.old
+   rm -f $BINDIR/$p2 $BINDIR/$p2.old
  fi
  cp $p $BINDIR/
  chmod $INSTALLPERMS $BINDIR/$p2
