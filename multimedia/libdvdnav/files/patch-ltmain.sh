--- ltmain.sh.orig	Mon Aug  5 16:46:18 2002
+++ ltmain.sh	Mon Aug  5 22:32:19 2002
@@ -961,6 +961,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -2507,7 +2508,7 @@
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test "$build_libtool_need_lc" = "yes"; then
-	      deplibs="$deplibs -lc"
+	      deplibs="$deplibs"
 	    fi
 	    ;;
 	  esac
@@ -4329,10 +4330,12 @@
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
