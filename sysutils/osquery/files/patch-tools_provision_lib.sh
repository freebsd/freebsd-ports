--- tools/provision/lib.sh.orig	2015-05-05 00:16:41 UTC
+++ tools/provision/lib.sh
@@ -57,27 +57,31 @@ function install_thrift() {
 
 function install_rocksdb() {
   if [[ ! -f /usr/local/lib/librocksdb.a ]]; then
-    if [[ ! -f rocksdb-3.5.tar.gz ]]; then
-      wget https://osquery-packages.s3.amazonaws.com/deps/rocksdb-3.5.tar.gz
+    if [[ ! -f rocksdb-3.10.2.tar.gz ]]; then
+      wget https://osquery-packages.s3.amazonaws.com/deps/rocksdb-3.10.2.tar.gz
     else
       log "rocksdb source is already downloaded. skipping."
     fi
-    if [[ ! -d rocksdb-rocksdb-3.5 ]]; then
-      tar -xf rocksdb-3.5.tar.gz
+    if [[ ! -d rocksdb-rocksdb-3.10.2 ]]; then
+      tar -xf rocksdb-3.10.2.tar.gz
     fi
-    if [[ ! -f rocksdb-rocksdb-3.5/librocksdb.a ]]; then
+    if [[ ! -f rocksdb-rocksdb-3.10.2/librocksdb.a ]]; then
       if [[ $OS = "ubuntu" ]]; then
         CLANG_INCLUDE="-I/usr/include/clang/3.4/include"
       elif [ $OS = "centos" ] || [ $OS = "rhel" ]; then
         CLANG_VERSION=`clang --version | grep version | cut -d" " -f3`
         CLANG_INCLUDE="-I/usr/lib/clang/$CLANG_VERSION/include"
       fi
-      pushd rocksdb-rocksdb-3.5
-      make static_lib CFLAGS="$CLANG_INCLUDE $CFLAGS"
+      pushd rocksdb-rocksdb-3.10.2
+      if [[ $OS = "freebsd" ]]; then
+        CC=cc CXX=c++ gmake static_lib CFLAGS="$CLANG_INCLUDE $CFLAGS"
+      else
+        make static_lib CFLAGS="$CLANG_INCLUDE $CFLAGS"
+      fi
       popd
     fi
-    sudo cp rocksdb-rocksdb-3.5/librocksdb.a /usr/local/lib
-    sudo cp -R rocksdb-rocksdb-3.5/include/rocksdb /usr/local/include
+    sudo cp rocksdb-rocksdb-3.10.2/librocksdb.a /usr/local/lib
+    sudo cp -R rocksdb-rocksdb-3.10.2/include/rocksdb /usr/local/include
   else
     log "rocksdb already installed. skipping."
   fi
@@ -253,7 +257,7 @@ function package() {
       brew install --build-bottle $1 || brew upgrade $@
     fi
   elif [[ $OS = "freebsd" ]]; then
-    if [[ -z "$(pkg info -q $1)" ]]; then
+    if pkg info -q $1; then
       log "$1 is already installed. skipping."
     else
       log "installing $1"
@@ -285,7 +289,7 @@ function remove_package() {
       log "Removing: $1 is not installed. skipping."
     fi
   elif [[ $OS = "freebsd" ]]; then
-    if [[ -n "$(pkg info -q $1)" ]]; then
+    if ! pkg info -q $1; then
       log "removing $1"
       sudo pkg delete -y $1
     else
