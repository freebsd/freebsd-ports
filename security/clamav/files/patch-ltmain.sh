--- ltmain.sh.orig	Sun Feb 15 12:44:09 2004
+++ ltmain.sh	Thu Mar 25 02:15:25 2004
@@ -1050,25 +1050,18 @@
 	    test "X$arg" = "X-lc" && continue
 	    ;;
 	  esac
-	 # This change is required for -lc_r under FreeBSD / Tomasz Kojm
-	 #elif test "X$arg" = "X-lc_r"; then
-	 # case $host in
-	 #*-*-openbsd* | *-*-freebsd*)
-	 #   # Do not include libc_r directly, use -pthread flag.
-	 #   continue
-	 #   ;;
-	 # esac
+	 elif test "X$arg" = "X-lc_r"; then
+	  case $host in
+	 *-*-openbsd* | *-*-freebsd4*)
+	    # Do not include libc_r directly, use -pthread flag.
+	    continue
+	    ;;
+	  esac
 	fi
 	deplibs="$deplibs $arg"
 	continue
 	;;
 
-      # We need this change for old -pthread *BSD style / Tomasz Kojm
-      -pthread)
-      	deplibs="$deplibs -pthread"
-      	continue
-      	;;
-
       -module)
 	module=yes
 	continue
@@ -4259,10 +4252,16 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	case $host in
+	*-*-freebsd*)
+	  # Do not install the useless pseudo-library
+	;;
+	*)
+	  name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
+	  instname="$dir/$name"i
+	  $show "$install_prog $instname $destdir/$name"
+	  $run eval "$install_prog $instname $destdir/$name" || exit $?
+	esac
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
