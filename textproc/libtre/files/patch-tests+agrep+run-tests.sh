--- tests/agrep/run-tests.sh.orig	2006-12-08 14:07:03.000000000 -0500
+++ tests/agrep/run-tests.sh	2008-08-05 09:56:07.263599354 -0400
@@ -2,7 +2,7 @@
 
 set -e
 
-agrep="$top_builddir/src/agrep"
+agrep="$top_builddir/src/tre_agrep"
 
 echo "$builddir $top_builddir $srcdir"
 
@@ -41,10 +41,10 @@
       # different platforms with regards to expanding \n (IRIX expands
       # it, others typically do not).  `cat' doesn't process its output.
       cat >> $out <<EOF
-#### TEST: agrep $extra $arg $input
+#### TEST: tre_agrep $extra $arg $input
 EOF
       cat <<EOF
-agrep $extra $arg $input
+tre_agrep $extra $arg $input
 EOF
       set +e
       $agrep $extra $arg $input >> $out
@@ -57,10 +57,10 @@
 
       num_expanded=`expr $num_expanded + 1`
       cat >> $out <<EOF
-#### TEST: agrep $extra $arg < $input
+#### TEST: tre_agrep $extra $arg < $input
 EOF
       cat <<EOF
-agrep $extra $arg < $input
+tre_agrep $extra $arg < $input
 EOF
       set +e
       $agrep $extra $arg < $input >> $out
