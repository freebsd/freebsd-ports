--- admin/ltmain.sh.orig	Mon Jun  7 02:20:19 2004
+++ admin/ltmain.sh	Mon Jun  7 02:24:08 2004
@@ -1123,6 +1123,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -1202,7 +1203,7 @@
       -l*)
 	if test "$arg" = "-lc"; then
 	  case $host in
-	  *-*-cygwin* | *-*-mingw* | *-*-pw32* | *-*-os2* | *-*-beos*)
+	  *-*-cygwin* | *-*-mingw* | *-*-pw32* | *-*-os2* | *-*-beos* | *-*-freebsd*)
 	    # These systems don't actually have c library (as such)
 	    continue
 	    ;;
@@ -2744,7 +2745,7 @@
       if test "$build_libtool_libs" = yes; then
 	if test -n "$rpath"; then
 	  case $host in
-	  *-*-cygwin* | *-*-mingw* | *-*-pw32* | *-*-os2* | *-*-beos*)
+	  *-*-cygwin* | *-*-mingw* | *-*-pw32* | *-*-os2* | *-*-beos* | *-*-freebsd*)
 	    # these systems don't actually have a c library (as such)!
 	    ;;
 	  *-*-rhapsody* | *-*-darwin1.[012])
@@ -4622,10 +4623,12 @@
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
