--- ltmain.sh.orig	Tue May 20 23:20:02 2003
+++ ltmain.sh	Thu Feb 12 20:46:44 2004
@@ -973,6 +973,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -2501,7 +2502,7 @@
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test $build_libtool_need_lc = "yes"; then
-	      deplibs="$deplibs -lc"
+	      deplibs="$deplibs"
 	    fi
 	    ;;
 	  esac
@@ -4325,10 +4326,12 @@
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
