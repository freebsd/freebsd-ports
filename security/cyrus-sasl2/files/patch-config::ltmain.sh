Index: config/ltmain.sh
diff -u config/ltmain.sh.orig config/ltmain.sh
--- config/ltmain.sh.orig	Tue Sep  3 23:59:40 2002
+++ config/ltmain.sh	Sat Oct 12 08:03:59 2002
@@ -3391,8 +3391,8 @@
 	# Install the pseudo-library for information purposes.
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	#$show "$install_prog $instname $destdir/$name"
+	#$run eval "$install_prog $instname $destdir/$name" || exit $?
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
