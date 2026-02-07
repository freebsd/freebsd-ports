--- autogen.sh.orig	2025-12-28 10:02:12 UTC
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
@@ -74,20 +49,3 @@ rm -f config.h config.h.in *~ #*
     > configure.ac
 
 rm -f config.h config.h.in *~ #*
-
-git submodule init
-git submodule update --remote
-
-if test -d "pro"; then
-N=`grep __FreeBSD__ third-party/clickhouse-cpp/clickhouse/base/platform.h|wc -l|tr -d "[[:space:]]"`
-if test "${N}" = "0"; then
- cd third-party/clickhouse-cpp/; cat ../../clickhouse/clickhouse-cpp.diff | patch -p1 ; cd ../..
-fi
-fi
-
-# git submodule update --init --recursive
-
-echo "Wait please..."
-autoreconf -if
-echo ""
-echo "Now run ./configure"
