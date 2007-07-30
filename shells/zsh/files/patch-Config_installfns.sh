--- Config/installfns.sh.orig	Mon Mar 20 08:06:24 2006
+++ Config/installfns.sh	Thu Jul 26 11:10:23 2007
@@ -45,10 +45,9 @@
       esac
     fi
     test -d $instdir || /bin/sh $sdir_top/mkinstalldirs $instdir || exit 1
+    $INSTALL_DATA $sdir_top/$file $instdir || exit 1
     if test -x $sdir_top/$file; then
-	$INSTALL_PROGRAM $sdir_top/$file $instdir || exit 1
-    else
-	$INSTALL_DATA $sdir_top/$file $instdir || exit 1
+       chmod +x $instdir/`echo $file | sed -e 's%^.*/%%'`
     fi
   fi
 done
