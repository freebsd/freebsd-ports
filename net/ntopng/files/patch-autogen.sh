--- autogen.sh.orig	2026-09-22 07:53:34 UTC
+++ autogen.sh
@@ -8,31 +8,6 @@ PKG_CONFIG=$(command -v pkg-config)
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
@@ -84,8 +59,3 @@ fi
 fi
 
 # git submodule update --init --recursive
-
-echo "Wait please..."
-autoreconf -if
-echo ""
-echo "Now run ./configure"
