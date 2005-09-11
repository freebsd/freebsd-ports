--- script/installswat.sh.orig	Thu Jul 28 19:44:16 2005
+++ script/installswat.sh	Wed Aug  3 02:33:04 2005
@@ -8,8 +8,7 @@
 echo Installing SWAT in $SWATDIR
 echo Installing the Samba Web Administration Tool
 
-LANGS=". `cd $SRCDIR../swat/; /bin/echo lang/??`"
-echo Installing langs are `cd $SRCDIR../swat/lang/; /bin/echo ??`
+LANGS="."
 
 for ln in $LANGS; do 
  SWATLANGDIR=$SWATDIR/$ln
