--- ltmain.sh.orig	Sat Feb  8 08:47:44 2003
+++ ltmain.sh	Tue Jul 15 13:06:35 2003
@@ -1075,7 +1075,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
@@ -1085,8 +1085,16 @@
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
 
@@ -2503,6 +2511,9 @@
 	  *-*-openbsd* | *-*-freebsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test $build_libtool_need_lc = "yes"; then
@@ -4330,10 +4341,12 @@
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
