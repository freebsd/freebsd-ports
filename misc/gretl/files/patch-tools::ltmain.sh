--- tools/ltmain.sh.orig	Mon Feb 10 02:23:55 2003
+++ tools/ltmain.sh	Mon Apr 14 12:23:06 2003
@@ -967,6 +967,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -4280,10 +4281,12 @@
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
