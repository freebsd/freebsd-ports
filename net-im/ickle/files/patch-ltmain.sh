--- ltmain.sh.orig	Sat Sep 22 20:10:52 2001
+++ ltmain.sh	Tue Nov 20 21:14:55 2001
@@ -4210,10 +4213,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
