--- ltmain.sh.old	Tue Jun  8 19:21:45 2004
+++ ltmain.sh	Tue Jun  8 19:40:03 2004
@@ -1356,7 +1356,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
@@ -1371,8 +1371,16 @@
 	continue
 	;;
 
+      -pthread)
+        compile_command="$compile_command -pthread"
+        finalize_command="$finalize_command -pthread"
+        compiler_flags="$compiler_flags -pthread"
+        continue
+        ;;
+
       -module)
 	module=yes
+        build_old_libs=no
 	continue
 	;;
 
@@ -3200,6 +3208,9 @@
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
+          *-*-freebsd*)
+            # FreeBSD doesn't need this . . .
+            ;;
  	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test "$build_libtool_need_lc" = "yes"; then
@@ -5550,10 +5561,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+        if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+        fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
