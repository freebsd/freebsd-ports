--- script/installswat.sh.orig	Fri Dec 17 03:59:34 2004
+++ script/installswat.sh	Fri Dec 17 04:01:34 2004
@@ -8,8 +8,7 @@
 echo Installing SWAT in $SWATDIR
 echo Installing the Samba Web Administration Tool
 
-LANGS=". `cd $SRCDIR../swat/; /bin/echo lang/??`"
-echo Installing langs are `cd $SRCDIR../swat/lang/; /bin/echo ??`
+LANGS="."
 
 for ln in $LANGS; do 
  SWATLANGDIR=$SWATDIR/$ln
