--- a/install.sh
+++ b/install.sh
@@ -148,7 +148,7 @@ function doInstall()
 
 	makeDir $LIBDIR 1 && cp -r template lib $LIBDIR || exit 1
 	makeDir $BINDIR || exit 1
-	makeDir $DOCDIR && cp -r contrib COPYING CREDITS HISTORY INSTALL LGPL.txt README* REQUIREMENTS FAQ $DOCDIR || exit 1
+	[ -n $NOPORTDOCS ] && makeDir $DOCDIR && cp -r contrib COPYING CREDITS HISTORY INSTALL LGPL.txt README* REQUIREMENTS FAQ $DOCDIR || exit 1
 	makeDir $MANDIR/man8 && cp vdradmind.pl.1 $MANDIR/man8/vdradmind.8 || exit 1
 
 	(
