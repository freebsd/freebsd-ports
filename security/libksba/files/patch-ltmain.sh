--- ltmain.sh.orig	Wed Jul 17 17:15:35 2002
+++ ltmain.sh	Wed Jul 17 17:17:15 2002
@@ -1060,8 +1060,16 @@
 	continue
 	;;
 
+      -pthread)
+	compile_command="$compile_command -pthread"
+	finalize_command="$finalize_command -pthread"
+	compiler_flags="$compiler_flags -pthread"
+	continue;
+	;;
+
       -module)
 	module=yes
+	build_old_libs=yes
 	continue
 	;;
 
@@ -4210,10 +4218,12 @@
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
