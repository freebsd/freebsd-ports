--- config/ltmain.sh.orig	Tue Sep  3 23:59:40 2002
+++ config/ltmain.sh	Sat Oct 12 08:03:59 2002
@@ -1894,7 +1894,7 @@
 	  if test $? -eq 0 ; then
 	    ldd_output=`ldd conftest`
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	      # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		libname=`eval \\$echo \"$libname_spec\"`
@@ -1919,7 +1919,7 @@
 	    # Error occured in the first compile.  Let's try to salvage the situation:
 	    # Compile a seperate program for each library.
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	     # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		$rm conftest
@@ -1959,7 +1959,7 @@
 	  set dummy $deplibs_check_method
 	  file_magic_regex="`expr \"$deplibs_check_method\" : \"$2 \(.*\)\"`"
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr X$a_deplib : 'X-l\(.*\)'`"
 	    # If $name is empty we are operating on a -L argument.
 	    if test "$name" != "" ; then
 	      libname=`eval \\$echo \"$libname_spec\"`
@@ -3391,8 +3391,8 @@
 	# Install the pseudo-library for information purposes.
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	#$show "$install_prog $instname $destdir/$name"
+	#$run eval "$install_prog $instname $destdir/$name" || exit $?
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
