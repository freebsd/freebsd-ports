--- ltmain.sh.orig	Sat Apr 19 21:11:30 2003
+++ ltmain.sh	Wed May 14 16:05:31 2003
@@ -1277,7 +1277,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
@@ -1287,8 +1287,16 @@
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
 
@@ -2997,6 +3005,9 @@
 	    # problems, so we reset it completely
 	    verstring=
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    verstring="0.0"
 	    ;;
@@ -5425,10 +5436,12 @@
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
