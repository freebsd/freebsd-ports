--- tools/provision/freebsd.sh.orig	2015-05-05 00:16:41 UTC
+++ tools/provision/freebsd.sh
@@ -12,6 +12,9 @@ function main_freebsd() {
   package git
   package python
   package py27-pip
+  package snappy
   package rocksdb
+  package thrift
   package thrift-cpp
+  package yara
 }
