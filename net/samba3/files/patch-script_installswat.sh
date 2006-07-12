--- script/installswat.sh.orig	Thu Apr 20 04:29:42 2006
+++ script/installswat.sh	Tue Apr 25 02:12:10 2006
@@ -21,8 +21,7 @@
 		;;
 esac
 
-LANGS=". `cd $SRCDIR../swat/; /bin/echo lang/??`"
-echo "langs are `cd $SRCDIR../swat/lang/; /bin/echo ??` "
+LANGS="."
 
 if test "$mode" = 'install'; then
  for ln in $LANGS; do 
