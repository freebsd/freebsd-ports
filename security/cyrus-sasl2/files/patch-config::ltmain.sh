Index: config/ltmain.sh
diff -u config/ltmain.sh.orig config/ltmain.sh
--- config/ltmain.sh.orig	Wed Jul  2 22:29:00 2003
+++ config/ltmain.sh	Wed Jul 16 02:57:20 2003
@@ -1901,7 +1901,7 @@
 		deplib_matches=`eval \\$echo \"$library_names_spec\"`
 		set dummy $deplib_matches
 		deplib_match=$2
-		if test `expr "$ldd_output" : ".*$deplib_match"` -ne 0 ; then
+		if test `expr "X$ldd_output" : "X.*$deplib_match"` -ne 0 ; then
 		  newdeplibs="$newdeplibs $i"
 		else
 		  droppeddeps=yes
@@ -1931,7 +1931,7 @@
 		  deplib_matches=`eval \\$echo \"$library_names_spec\"`
 		  set dummy $deplib_matches
 		  deplib_match=$2
-		  if test `expr "$ldd_output" : ".*$deplib_match"` -ne 0 ; then
+		  if test `expr "X$ldd_output" : "X.*$deplib_match"` -ne 0 ; then
 		    newdeplibs="$newdeplibs $i"
 		  else
 		    droppeddeps=yes
@@ -3396,8 +3396,8 @@
 	# Install the pseudo-library for information purposes.
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	#$show "$install_prog $instname $destdir/$name"
+	#$run eval "$install_prog $instname $destdir/$name" || exit $?
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
