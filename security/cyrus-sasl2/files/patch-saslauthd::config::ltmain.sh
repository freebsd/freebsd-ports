Index: saslauthd/config/ltmain.sh
diff -u saslauthd/config/ltmain.sh.orig saslauthd/config/ltmain.sh
--- saslauthd/config/ltmain.sh.orig	Wed Apr 16 07:28:26 2003
+++ saslauthd/config/ltmain.sh	Tue Jul  1 01:24:38 2003
@@ -1959,7 +1959,7 @@
 	  set dummy $deplibs_check_method
 	  file_magic_regex="`expr \"$deplibs_check_method\" : \"$2 \(.*\)\"`"
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr X$a_deplib : 'X-l\(.*\)'`"
 	    # If $name is empty we are operating on a -L argument.
 	    if test "$name" != "" ; then
 	      libname=`eval \\$echo \"$libname_spec\"`
