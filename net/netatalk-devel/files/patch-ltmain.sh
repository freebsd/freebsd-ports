--- ltmain.sh.orig	Sat Nov 29 08:54:27 2003
+++ ltmain.sh	Sun Dec  7 13:32:36 2003
@@ -1286,7 +1286,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
@@ -1913,6 +1913,9 @@
 	      finalize_deplibs="$deplib $finalize_deplibs"
 	    fi
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    $echo "$modename: warning: \`-L' is ignored for archives/objects" 1>&2
 	    ;;
@@ -5474,10 +5477,12 @@
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
