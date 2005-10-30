--- srclib/apr/buildconf.orig	Tue Jun 14 14:11:15 2005
+++ srclib/apr/buildconf	Sun Oct 30 19:47:52 2005
@@ -23,7 +23,7 @@
 #
 build/buildcheck.sh || exit 1
 
-libtoolize=`build/PrintPath glibtoolize libtoolize15 libtoolize14 libtoolize`
+libtoolize="${LIBTOOLIZE}"
 if [ "x$libtoolize" = "x" ]; then
     echo "libtoolize not found in path"
     exit 1
@@ -52,7 +52,7 @@
    # Expecting the code above to be very portable, but just in case...
    if [ -z "$ltfile" -o ! -f "$ltfile" ]; then
      ltpath=`dirname $libtoolize`
-     ltfile=`cd $ltpath/../share/aclocal ; pwd`/libtool.m4
+     ltfile=${LIBTOOL_M4-`cd $ltpath/../../share/aclocal ; pwd`/${LIBTOOL_VERSION}.m4}
    fi
 fi
   
@@ -61,7 +61,7 @@
     exit 1
 fi
 
-echo "buildconf: Using libtool.m4 at ${ltfile}."
+echo "buildconf: Using libtool${LIBTOOL_VERSION}.m4 at ${ltfile}."
 
 cat $ltfile | sed -e 's/LIBTOOL=\(.*\)top_build/LIBTOOL=\1apr_build/' > build/libtool.m4
 
