--- srclib/apr/build/ltmain.sh.orig	Sun Apr  7 23:04:28 2002
+++ srclib/apr/build/ltmain.sh	Sun Apr  7 23:05:33 2002
@@ -1959,14 +1959,14 @@
 	  if test $? -eq 0 ; then
 	    ldd_output=`ldd conftest`
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr -- $i : '-l\(.*\)'`"
 	      # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		libname=`eval \\$echo \"$libname_spec\"`
 		deplib_matches=`eval \\$echo \"$library_names_spec\"`
 		set dummy $deplib_matches
 		deplib_match=$2
-		if test `expr "$ldd_output" : ".*$deplib_match"` -ne 0 ; then
+		if test `expr -- "$ldd_output" : ".*$deplib_match"` -ne 0 ; then
 		  newdeplibs="$newdeplibs $i"
 		else
 		  droppeddeps=yes
@@ -1984,7 +1984,7 @@
 	    # Error occured in the first compile.  Let's try to salvage the situation:
 	    # Compile a seperate program for each library.
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr -- $i : '-l\(.*\)'`"
 	     # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		$rm conftest
@@ -1996,7 +1996,7 @@
 		  deplib_matches=`eval \\$echo \"$library_names_spec\"`
 		  set dummy $deplib_matches
 		  deplib_match=$2
-		  if test `expr "$ldd_output" : ".*$deplib_match"` -ne 0 ; then
+		  if test `expr -- "$ldd_output" : ".*$deplib_match"` -ne 0 ; then
 		    newdeplibs="$newdeplibs $i"
 		  else
 		    droppeddeps=yes
@@ -2022,9 +2022,9 @@
 	  ;;
 	file_magic*)
 	  set dummy $deplibs_check_method
-	  file_magic_regex="`expr \"$deplibs_check_method\" : \"$2 \(.*\)\"`"
+	  file_magic_regex="`expr -- \"$deplibs_check_method\" : \"$2 \(.*\)\"`"
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr -- $a_deplib : '-l\(.*\)'`"
 	    # If $name is empty we are operating on a -L argument.
 	    if test "$name" != "" ; then
 	      libname=`eval \\$echo \"$libname_spec\"`
