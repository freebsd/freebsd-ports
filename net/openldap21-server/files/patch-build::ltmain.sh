--- build/ltmain.sh.orig	Mon Feb 10 20:24:24 2003
+++ build/ltmain.sh	Thu Mar 25 02:17:45 2004
@@ -1066,7 +1066,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
@@ -4286,10 +4286,17 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	case $host in
+	*-*-freebsd*)
+	  # Do not install the useless pseudo-library
+	  ;;
+	*)
+	  name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
+	  instname="$dir/$name"i
+	  $show "$install_prog $instname $destdir/$name"
+	  $run eval "$install_prog $instname $destdir/$name" || exit $?
+	  ;;
+	esac
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
