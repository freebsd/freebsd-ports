
$FreeBSD$

--- ../db-3.1.17/dist/ltmain.sh.orig	Sun Jul 30 20:45:53 2000
+++ ../db-3.1.17/dist/ltmain.sh	Fri Dec 14 19:32:11 2001
@@ -2694,6 +2694,9 @@
 	    # Absolute path.
 	    rpath="$rpath$dir:"
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    # Relative path: add a thisdir entry.
 	    rpath="$rpath\$thisdir/$dir:"
@@ -3356,10 +3359,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
