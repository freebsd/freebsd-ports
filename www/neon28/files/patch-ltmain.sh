--- ltmain.sh.orig	Wed Jan 23 11:38:40 2002
+++ ltmain.sh	Sun Feb  3 01:44:17 2002
@@ -1037,8 +1037,16 @@
 	continue
 	;;
 
+      -pthread)
+	compile_command="$compile_command -pthread"
+	finalize_command="$finalize_command -pthread"
+	compiler_flags="$compiler_flags -pthread"
+	continue
+	;;
+
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
@@ -4179,10 +4190,12 @@
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
