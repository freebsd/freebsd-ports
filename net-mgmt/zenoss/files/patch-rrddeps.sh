$FreeBSD$

--- rrddeps.sh.orig	2011-02-08 16:07:00.000000000 +0000
+++ rrddeps.sh	2011-06-25 12:42:21.985461786 +0100
@@ -44,6 +44,13 @@
 
 export CFLAGS="-O3 -fPIC -I${INSTALL_DIR}/include"
 
+USES+= gettext
+CPPFLAGS+=" -I${INSTALL_DIR}/include"
+LDFLAGS+=" -L${INSTALL_DIR}/lib"
+
+GNU_CONFIGURE=yes
+CONFIGURE_ENV="CPPFLAGS= -I${INSTALL_DIR}/include  LDFLAGS=-L${INSTALL_DIR}/lib"
+
 build_dep () {
   if [ -e $BUILD_DIR/$dep-* ]
   then
@@ -56,15 +63,29 @@
       patch -p0 <$RRDDEPS_DIR/$patch >>$BUILDLOG 2>&1 || exit $?
     fi
     cd $dep-* || exit $?
-    echo "configuring: $dep"
-    ./configure --prefix=$ZENHOME $confopts >>$BUILDLOG 2>&1 || exit $?
-    echo "building: $dep"
-    make >>$BUILDLOG 2>&1 || exit $?
-    echo "installing: $dep"
-    make install DESTDIR="" >>$BUILDLOG 2>&1 || exit $?
-    if [ -n "$DESTDIR" ] && [ "$DESTDIR" != "/" ]
+
+    sed -i.bak -e "s#^\(pkgconfigdir\).*#\1 = ${PKG_CONFIG_PATH}#" Makefile.in
+
+    if [ "$dep" = "freetype" ]
     then
-      make install DESTDIR="$DESTDIR" >>$BUILDLOG 2>&1 || exit $?
+      GNUMAKE=gmake ./configure --prefix=$ZENHOME $confopts || exit $?
+      gmake || exit $?
+      gmake install DESTDIR="" || exit $?
+      if [ -n "$DESTDIR" ] && [ "$DESTDIR" != "/" ]
+      then
+          gmake install DESTDIR="$DESTDIR" || exit $?
+      fi
+      else
+        echo "configuring: $dep"
+        ./configure --prefix=$ZENHOME $confopts >>$BUILDLOG 2>&1 || exit $?
+        echo "building: $dep"
+        make >>$BUILDLOG 2>&1 || exit $?
+        echo "installing: $dep"
+        make install DESTDIR="" >>$BUILDLOG 2>&1 || exit $?
+        if [ -n "$DESTDIR" ] && [ "$DESTDIR" != "/" ]
+        then
+            make install DESTDIR="$DESTDIR" >>$BUILDLOG 2>&1 || exit $?
+        fi
     fi
     cd ..
   fi
@@ -75,6 +96,11 @@
 patch=""
 build_dep
 
+dep=libiconv
+confopts=''
+patch=""
+build_dep
+
 dep=gettext
 confopts=''
 patch="gettext-0.17.all.patch01"
@@ -115,13 +141,6 @@
 patch=""
 build_dep
 
-if [ "$os_name" == "Darwin" ]; then
-    dep=libiconv
-    confopts=''
-    patch=""
-    build_dep
-fi
-
 dep=cairo
 confopts='--enable-xlib=no --enable-xlib-render=no --enable-win32=no'
 patch="cairo-1.8.4.Darwin.patch01"
