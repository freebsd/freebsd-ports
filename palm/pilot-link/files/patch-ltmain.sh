--- ltmain.sh.orig	2009-05-25 07:33:24.000000000 +0300
+++ ltmain.sh	2009-09-08 01:58:54.000000000 +0300
@@ -2077,10 +2077,10 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
-	func_basename "$file"
-	name="$func_basename_result"
-	instname="$dir/$name"i
-	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
+#	func_basename "$file"
+#	name="$func_basename_result"
+#	instname="$dir/$name"i
+#	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
