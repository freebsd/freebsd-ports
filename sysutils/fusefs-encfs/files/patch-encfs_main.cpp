--- encfs/main.cpp.orig	2015-03-24 20:45:16 UTC
+++ encfs/main.cpp
@@ -27,6 +27,7 @@
 #include <sys/time.h>
 #include <cerrno>
 #include <cstring>
+#include <cstdlib>
 
 #include <getopt.h>
 
@@ -599,7 +600,7 @@ int main(int argc, char *argv[]) {
   encfs_oper.init = encfs_init;
   encfs_oper.destroy = encfs_destroy;
   // encfs_oper.access = encfs_access;
-  // encfs_oper.create = encfs_create;
+  encfs_oper.create = encfs_create;
   encfs_oper.ftruncate = encfs_ftruncate;
   encfs_oper.fgetattr = encfs_fgetattr;
   // encfs_oper.lock = encfs_lock;
