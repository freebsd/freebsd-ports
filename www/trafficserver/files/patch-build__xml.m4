--- ./build/xml.m4.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./build/xml.m4	2014-01-27 08:45:49.000000000 +0000
@@ -59,7 +59,7 @@
       elif test "$withval" != "no"; then
         enable_libxml2=yes
         libxml2_include="$withval/include/libxml2"
-        libxml2_ldflags="$withval/lib"
+        libxml2_ldflags="-L$withval/lib"
       fi
     fi
   ])
