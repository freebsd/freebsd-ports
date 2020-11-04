--- autogen.sh.orig	2020-11-02 21:27:19 UTC
+++ autogen.sh
@@ -8,31 +8,6 @@ LIBTOOLIZE=$(command -v libtoolize)
 AUTORECONF=$(command -v autoreconf)
 PKG_CONFIG=$(command -v pkg-config)
 
-if test -z $AUTOCONF; then
-    echo "autoconf is missing: please install it and try again"
-    exit
-fi
-
-if test -z $AUTOMAKE; then
-    echo "automake is missing: please install it and try again"
-    exit
-fi
-
-if test -z $LIBTOOL && test -z $LIBTOOLIZE ; then
-    echo "libtool and libtoolize is missing: please install it and try again"
-    exit
-fi
-
-if test -z $AUTORECONF; then
-    echo "autoreconf is missing: please install it and try again"
-    exit
-fi
-
-if test -z $PKG_CONFIG; then
-    echo "pkg-config is missing: please install it (apt-get install pkg-config) and try again"
-    exit
-fi
-
 ##########################################
 
 TODAY=`date +%y%m%d`
@@ -73,8 +48,3 @@ cat configure.seed | sed \
     > configure.ac
 
 rm -f config.h config.h.in *~ #*
-
-echo "Wait please..."
-autoreconf -if
-echo ""
-echo "Now run ./configure"
