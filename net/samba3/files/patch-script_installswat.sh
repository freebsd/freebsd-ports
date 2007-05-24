--- ./script/installswat.sh.orig	Thu Mar  1 05:55:02 2007
+++ ./script/installswat.sh	Tue Apr 17 02:06:59 2007
@@ -21,8 +21,7 @@
 		;;
 esac
 
-LANGS=". `cd $SRCDIR../swat/; /bin/echo lang/??`"
-echo "langs are `cd $SRCDIR../swat/lang/; /bin/echo ??` "
+LANGS="."
 
 if test "$mode" = 'install'; then
  for ln in $LANGS; do 
