--- config/libtool.m4.orig	2016-05-12 15:26:58 UTC
+++ config/libtool.m4
@@ -1866,6 +1866,12 @@ else
   lt_cv_dlopen_libs=
 
   case $host_os in
+  FreeBSD*)
+    lt_cv_dlopen="dlopen"
+    lt_cv_dlopen_libs=""
+    lt_cv_dlopen_self=yes
+    ;;
+
   beos*)
     lt_cv_dlopen="load_add_on"
     lt_cv_dlopen_libs=
