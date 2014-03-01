--- a/install.sh
+++ b/install.sh
@@ -146,27 +146,27 @@ function doInstall()
 
 	perlModules
 
-	makeDir $LIBDIR 1 && cp -r template lib $LIBDIR || exit 1
-	makeDir $BINDIR || exit 1
-	makeDir $DOCDIR && cp -r contrib COPYING CREDITS HISTORY INSTALL LGPL.txt README* REQUIREMENTS FAQ $DOCDIR || exit 1
-	makeDir $MANDIR/man8 && cp vdradmind.pl.1 $MANDIR/man8/vdradmind.8 || exit 1
+	makeDir $DESTDIR$LIBDIR 1 && cp -r template lib $DESTDIR$LIBDIR || exit 1
+	makeDir $DESTDIR$BINDIR || exit 1
+	[ -n $NOPORTDOCS ] && makeDir $DESTDIR$DOCDIR && cp -r contrib COPYING CREDITS HISTORY INSTALL LGPL.txt README* REQUIREMENTS FAQ $DESTDIR$DOCDIR || exit 1
+	makeDir $DESTDIR$MANDIR/man8 && cp vdradmind.pl.1 $DESTDIR$MANDIR/man8/vdradmind.8 || exit 1
 
 	(
 		cd locale
 		for lang in *
 		do
-			makeDir $LOCDIR/$lang/LC_MESSAGES/ && install -m 644 $lang/LC_MESSAGES/vdradmin.mo $LOCDIR/$lang/LC_MESSAGES/vdradmin.mo || exit 1
+			makeDir $DESTDIR$LOCDIR/$lang/LC_MESSAGES/ && install -m 644 $lang/LC_MESSAGES/vdradmin.mo $DESTDIR$LOCDIR/$lang/LC_MESSAGES/vdradmin.mo || exit 1
 		done
 	)
 
 	local RESTART=
-	if [ -d $BINDIR ]; then
+	if [ -d $DESTDIR$BINDIR ]; then
 		killRunningVDRAdmin
 		if [ $? -ne 0 ] ; then
 			RESTART=1
 			echo "Killed running VDRAdmin-AM..."
 		fi
-		sed <vdradmind.pl >$BINDIR/vdradmind \
+		sed <vdradmind.pl >$DESTDIR$BINDIR/vdradmind \
 		    -e "s/^\(my \$SEARCH_FILES_IN_SYSTEM *=\) 0;/\1 1;/" \
 		    -e "s:/usr/share/vdradmin/lib:${LIBDIR}/lib:" \
 		    -e "s:/usr/share/vdradmin/template:${LIBDIR}/template:" \
@@ -179,7 +179,7 @@ function doInstall()
 		    -e "s:\(\$CONFIG{EPGIMAGES} *= \)\"\$CONFIG{VIDEODIR}/epgimages\";:\1\"${EPGIMAGES}\";:" \
 				-e "s:\(\$CONFIG{VDRCONFDIR} *= \)\"\$CONFIG{VIDEODIR}\";:\1\"${VDRCONF}\";:"
 
-		chmod a+x  $BINDIR/vdradmind
+		chmod a+x  $DESTDIR$BINDIR/vdradmind
 
 		if [ "$CONFIG" ]; then
 			echo "Configuring VDRAdmin-AM..."
@@ -192,14 +192,14 @@ function doInstall()
 		fi
 
 		echo ""
-		if [ -e $BINDIR/vdradmind.pl ]; then
-			echo "Removing ancient $BINDIR/vdradmind.pl"
-			rm -f $BINDIR/vdradmind.pl
+		if [ -e $DESTDIR$BINDIR/vdradmind.pl ]; then
+			echo "Removing ancient $DESTDIR$BINDIR/vdradmind.pl"
+			rm -f $DESTDIR$BINDIR/vdradmind.pl
 		fi
 		for man in man1/vdradmind.pl.1 man1/vdradmind.1; do
-			if [ -e $MANDIR/$man ]; then
-				echo "Removing ancient $MANDIR/$man"
-				rm -f $MANDIR/$man
+			if [ -e $DESTDIR$MANDIR/$man ]; then
+				echo "Removing ancient $DESTDIR$MANDIR/$man"
+				rm -f $DESTDIR$MANDIR/$man
 			fi
 		done
 	else
