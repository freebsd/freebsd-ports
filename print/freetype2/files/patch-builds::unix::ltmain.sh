
$FreeBSD$

--- builds/unix/ltmain.sh	2001/07/12 07:56:54	1.1
+++ builds/unix/ltmain.sh	2001/07/12 07:57:15
@@ -4175,10 +4175,12 @@
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
