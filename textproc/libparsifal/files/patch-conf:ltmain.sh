--- conf/ltmain.sh.orig	Tue Jan  6 14:43:27 2004
+++ conf/ltmain.sh	Tue Jan  6 14:43:42 2004
@@ -4247,10 +4247,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false ; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
