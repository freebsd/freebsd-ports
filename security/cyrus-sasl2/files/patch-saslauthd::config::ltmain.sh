--- saslauthd/config/ltmain.sh.orig	Tue Dec  4 03:06:57 2001
+++ saslauthd/config/ltmain.sh	Tue Apr 15 02:33:18 2003
@@ -1861,7 +1861,7 @@
 	  if test $? -eq 0 ; then
 	    ldd_output=`ldd conftest`
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	      # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		libname=`eval \\$echo \"$libname_spec\"`
@@ -1886,7 +1886,7 @@
 	    # Error occured in the first compile.  Let's try to salvage the situation:
 	    # Compile a seperate program for each library.
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	     # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		$rm conftest
@@ -1926,7 +1926,7 @@
 	  set dummy $deplibs_check_method
 	  file_magic_regex="`expr \"$deplibs_check_method\" : \"$2 \(.*\)\"`"
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr X$a_deplib : 'X-l\(.*\)'`"
 	    # If $name is empty we are operating on a -L argument.
 	    if test "$name" != "" ; then
 	      libname=`eval \\$echo \"$libname_spec\"`
