--- ltmain.sh.orig	Mon Apr  5 19:24:18 2004
+++ ltmain.sh	Tue Jun  1 20:45:09 2004
@@ -1346,7 +1346,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
@@ -1361,8 +1361,16 @@
 	continue
 	;;
 
+      -pthread)
+      compile_command="$compile_command -pthread"
+      finalize_command="$finalize_command -pthread"
+      compiler_flags="$compiler_flags -pthread"
+      continue
+      ;;
+
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
@@ -3056,6 +3064,9 @@
 	    # problems, so we reset it completely
 	    verstring=
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    verstring="0.0"
 	    ;;
@@ -5528,10 +5539,12 @@
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
