--- admin/ltmain.sh.orig	Sun Mar 10 00:03:33 2002
+++ admin/ltmain.sh	Tue Jan  7 21:37:22 2003
@@ -1123,6 +1123,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -1206,6 +1207,10 @@
 	    # These systems don't actually have c library (as such)
 	    continue
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    continue
+	    ;;
 	  *-*-rhapsody* | *-*-darwin1.[012])
 	    # Rhapsody C library is in the System framework
 	    deplibs="$deplibs -framework System"
@@ -2747,6 +2752,9 @@
 	  *-*-cygwin* | *-*-mingw* | *-*-pw32* | *-*-os2* | *-*-beos*)
 	    # these systems don't actually have a c library (as such)!
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *-*-rhapsody* | *-*-darwin1.[012])
 	    # Rhapsody C library is in the System framework
 	    deplibs="$deplibs -framework System"
@@ -4622,10 +4630,12 @@
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
