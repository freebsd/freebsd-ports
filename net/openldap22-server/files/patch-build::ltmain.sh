--- build/ltmain.sh.orig	Sun Feb  9 23:24:29 2003
+++ build/ltmain.sh	Fri Jun 20 21:37:02 2003
@@ -4285,12 +4285,6 @@
 	  IFS="$save_ifs"
 	fi
 
-	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
-
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
 	;;
