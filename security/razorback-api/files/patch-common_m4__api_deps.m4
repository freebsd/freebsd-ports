--- ./common_m4/api_deps.m4.orig	2014-08-20 10:21:22.000000000 -0400
+++ ./common_m4/api_deps.m4	2014-08-20 10:21:36.000000000 -0400
@@ -55,7 +55,7 @@
 #          [AC_MSG_ERROR("curl header file not found")]
 #     )
 
-PKG_CHECK_MODULES([JSON], [json >= 0.9])
+PKG_CHECK_MODULES([JSON], [json-c >= 0.9])
 
 CFLAGS="$JSON_CFLAGS $CFLAGS"
 LIBS="$JSON_LIBS $LIBS"
