--- build_modssl_with_npn.sh.org	2012-03-31 16:28:55.660831000 +0900
+++ build_modssl_with_npn.sh	2012-03-31 21:14:56.155134872 +0900
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
@@ -105,9 +105,6 @@
 OPENSSL_INST_ROOT=${OPENSSL_SRC_ROOT}_install
 APACHE_HTTPD_SRC_ROOT=${APACHE_HTTPD_SRC_TGZ%.tar.gz}
 
-OPENSSL_BUILDLOG=$(mktemp -p /tmp openssl_buildlog.XXXXXXXXXX)
-APACHE_HTTPD_BUILDLOG=$(mktemp -p /tmp httpd_buildlog.XXXXXXXXXX)
-
 cp $APACHE_HTTPD_MODSSL_NPN_PATCH_PATH $BUILDROOT/$APACHE_HTTPD_MODSSL_NPN_PATCH
 
 pushd $BUILDROOT >/dev/null
@@ -140,9 +137,9 @@
 if [ ! -f "$PROGRESS_DIR/openssl_configured" ]; then
   pushd $OPENSSL_SRC_ROOT >/dev/null
   echo -n "Configuring OpenSSL ... "
-  ./config no-shared -fPIC --openssldir=$BUILDROOT/$OPENSSL_INST_ROOT >> $OPENSSL_BUILDLOG
+  ./config no-shared -fPIC --openssldir=$BUILDROOT/$OPENSSL_INST_ROOT
   if [ $? -ne 0 ]; then
-    echo "Failed. Build log at $OPENSSL_BUILDLOG."
+    echo "Failed at configuring OpenSSL."
     do_cleanup
   fi
   echo "done"
@@ -155,9 +152,9 @@
 if [ ! -f "$PROGRESS_DIR/openssl_built" ]; then
   pushd $OPENSSL_SRC_ROOT >/dev/null
   echo -n "Building OpenSSL (this may take a while) ... "
-  make install >> $OPENSSL_BUILDLOG 2>&1
+  make install
   if [ $? -ne 0 ]; then
-    echo "Failed. Build log at $OPENSSL_BUILDLOG."
+    echo "Failed at building OpenSSL."
     do_cleanup
   fi
   echo "done"
@@ -167,7 +164,6 @@
   echo "Already built OpenSSL."
 fi
 
-rm -f "$OPENSSL_BUILDLOG"
 
 echo ""
 
@@ -185,11 +181,11 @@
   # not only libraries in Libs, but also those in Libs.private:
   mv configure configure.bak
   sed 's/--libs-only-l openssl/--libs-only-l --static openssl/' configure.bak > configure
-  chmod --reference=configure.bak configure
+  chmod 755 configure
 
-  ./configure --enable-ssl=shared --with-ssl=$BUILDROOT/$OPENSSL_INST_ROOT >> $APACHE_HTTPD_BUILDLOG
+  ./configure --enable-ssl=shared --with-ssl=$BUILDROOT/$OPENSSL_INST_ROOT
   if [ $? -ne 0 ]; then
-    echo "Failed. Build log at $APACHE_HTTPD_BUILDLOG."
+    echo "Failed at configuring Apache mod_ssl."
     do_cleanup
   fi
   echo "done"
@@ -202,9 +198,9 @@
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
@@ -214,8 +210,6 @@
   echo "Already built Apache mod_ssl."
 fi
 
-rm -f "$APACHE_HTTPD_BUILDLOG"
-
 popd >/dev/null  # $BUILDROOT
 
 MODSSL_SO_SRCPATH=$(find $BUILDROOT/$APACHE_HTTPD_SRC_ROOT -name mod_ssl.so)
