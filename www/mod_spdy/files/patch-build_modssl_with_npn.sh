--- build_modssl_with_npn.sh.orig	2013-10-29 15:17:22.000000000 +0900
+++ build_modssl_with_npn.sh	2013-10-30 16:12:09.000000000 +0900
@@ -33,7 +33,7 @@
 fi
 
 if [ -z "$BUILDROOT" ]; then
-  BUILDROOT=$(mktemp -d)
+  BUILDROOT=$(mktemp -d temp)
   REMOVE_BUILDROOT=1
 else
   REMOVE_BUILDROOT=0
@@ -72,7 +72,7 @@
   if [ ! -f "$PROGRESS_DIR/$2.downloaded" ]; then
     echo "Downloading $1"
     curl -f -# "$1" -o $2 || do_cleanup
-    if [[ $(md5sum $2 | cut -d\  -f1) != $3 ]]; then
+    if [[ $(md5 $2 | cut -d\  -f4) != $3 ]]; then
       echo "md5sum mismatch for $2"
       do_cleanup
     fi
@@ -93,31 +93,22 @@
   fi
 }
 
-OPENSSL_SRC_TGZ_URL="http://www.openssl.org/source/openssl-1.0.1c.tar.gz"
 APACHE_HTTPD_SRC_TGZ_URL="http://archive.apache.org/dist/httpd/httpd-2.2.22.tar.gz"
 APACHE_HTTPD_MODSSL_NPN_PATCH_PATH="$(dirname $0)/scripts/mod_ssl_with_npn.patch"
 
-OPENSSL_SRC_TGZ=$(basename $OPENSSL_SRC_TGZ_URL)
 APACHE_HTTPD_SRC_TGZ=$(basename $APACHE_HTTPD_SRC_TGZ_URL)
 APACHE_HTTPD_MODSSL_NPN_PATCH="mod_ssl_npn.patch"
 
-OPENSSL_SRC_ROOT=${OPENSSL_SRC_TGZ%.tar.gz}
-OPENSSL_INST_ROOT=${OPENSSL_SRC_ROOT}_install
 APACHE_HTTPD_SRC_ROOT=${APACHE_HTTPD_SRC_TGZ%.tar.gz}
 
-OPENSSL_BUILDLOG=$(mktemp -p /tmp openssl_buildlog.XXXXXXXXXX)
-APACHE_HTTPD_BUILDLOG=$(mktemp -p /tmp httpd_buildlog.XXXXXXXXXX)
-
 cp $APACHE_HTTPD_MODSSL_NPN_PATCH_PATH $BUILDROOT/$APACHE_HTTPD_MODSSL_NPN_PATCH
 
 pushd $BUILDROOT >/dev/null
 
-download_file $OPENSSL_SRC_TGZ_URL $OPENSSL_SRC_TGZ ae412727c8c15b67880aef7bd2999b2e
 download_file $APACHE_HTTPD_SRC_TGZ_URL $APACHE_HTTPD_SRC_TGZ d77fa5af23df96a8af68ea8114fa6ce1
 
 echo ""
 
-uncompress_file $OPENSSL_SRC_TGZ
 uncompress_file $APACHE_HTTPD_SRC_TGZ
 
 if [ ! -f "$PROGRESS_DIR/modssl_patched" ]; then
@@ -137,45 +128,6 @@
 
 echo ""
 
-if [ ! -f "$PROGRESS_DIR/openssl_configured" ]; then
-  pushd $OPENSSL_SRC_ROOT >/dev/null
-  echo -n "Configuring OpenSSL ... "
-  ./config no-shared -fPIC --openssldir=$BUILDROOT/$OPENSSL_INST_ROOT >> $OPENSSL_BUILDLOG
-  if [ $? -ne 0 ]; then
-    echo "Failed. Build log at $OPENSSL_BUILDLOG."
-    do_cleanup
-  fi
-  echo "done"
-  popd >/dev/null  # $OPENSSL_SRC_ROOT
-  touch "$PROGRESS_DIR/openssl_configured"
-else
-  echo "Already configured OpenSSL."
-fi
-
-if [ ! -f "$PROGRESS_DIR/openssl_built" ]; then
-  pushd $OPENSSL_SRC_ROOT >/dev/null
-  echo -n "Building OpenSSL (this may take a while) ... "
-  make install >> $OPENSSL_BUILDLOG 2>&1
-  if [ $? -ne 0 ]; then
-    echo "Failed. Build log at $OPENSSL_BUILDLOG."
-    do_cleanup
-  fi
-  # A hacky fix that helps things build on CentOS:
-  if grep -q CentOS /etc/issue; then
-    sed --in-place 's/^Libs\.private: -ldl$/& -lcrypto/' \
-      $BUILDROOT/$OPENSSL_INST_ROOT/lib/pkgconfig/openssl.pc
-  fi
-  echo "done"
-  popd >/dev/null  # $OPENSSL_SRC_ROOT
-  touch "$PROGRESS_DIR/openssl_built"
-else
-  echo "Already built OpenSSL."
-fi
-
-rm -f "$OPENSSL_BUILDLOG"
-
-echo ""
-
 if [ ! -f "$PROGRESS_DIR/modssl_configured" ]; then
   pushd $APACHE_HTTPD_SRC_ROOT >/dev/null
   echo -n "Configuring Apache mod_ssl ... "
@@ -190,11 +142,11 @@
   # not only libraries in Libs, but also those in Libs.private:
   mv configure configure.bak
   sed 's/--libs-only-l openssl/--libs-only-l --static openssl/' configure.bak > configure
-  chmod --reference=configure.bak configure
+  chmod 755 configure
 
-  ./configure --enable-ssl=shared --with-ssl=$BUILDROOT/$OPENSSL_INST_ROOT >> $APACHE_HTTPD_BUILDLOG
+  eval ${CONFIGURE_ENV} ./configure --enable-ssl=shared --with-ssl=%%OPENSSLBASE%%
   if [ $? -ne 0 ]; then
-    echo "Failed. Build log at $APACHE_HTTPD_BUILDLOG."
+    echo "Failed at configuring Apache mod_ssl."
     do_cleanup
   fi
   echo "done"
@@ -207,9 +159,9 @@
 if [ ! -f "$PROGRESS_DIR/modssl_built" ]; then
   pushd $APACHE_HTTPD_SRC_ROOT >/dev/null
   echo -n "Building Apache mod_ssl (this may take a while) ... "
-  make >> $APACHE_HTTPD_BUILDLOG 2>&1
+  make
   if [ $? -ne 0 ]; then
-    echo "Failed. Build log at $APACHE_HTTPD_BUILDLOG."
+    echo "Failed at building Apache mod_ssl."
     do_cleanup
   fi
   echo "done"
@@ -219,8 +171,6 @@
   echo "Already built Apache mod_ssl."
 fi
 
-rm -f "$APACHE_HTTPD_BUILDLOG"
-
 popd >/dev/null  # $BUILDROOT
 
 MODSSL_SO_SRCPATH=$(find $BUILDROOT/$APACHE_HTTPD_SRC_ROOT -name mod_ssl.so)
