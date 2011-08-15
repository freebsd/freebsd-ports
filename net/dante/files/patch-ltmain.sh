--- ltmain.sh.orig	2008-08-12 19:06:26.000000000 +0200
+++ ltmain.sh	2011-07-12 16:01:37.595732703 +0200
@@ -6115,10 +6115,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $extra_mode $instname $destdir/$name"
 	$run eval "$install_prog $extra_mode $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
