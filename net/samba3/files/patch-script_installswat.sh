--- script/installswat.sh.orig	Fri Nov 19 21:11:15 2004
+++ script/installswat.sh	Fri Nov 19 21:11:45 2004
@@ -103,7 +103,7 @@
               fi
           fi
           for f in $SRCDIR../docs/$dir/images/*.png; do
-              FNAME=$INSTALLDIR/`basename $f`
+              FNAME=$INSTALLDIR/images/`basename $f`
               echo $FNAME
               cp $f $FNAME || echo Cannot install $FNAME. Does $USER have privileges?
               chmod 0644 $FNAME
