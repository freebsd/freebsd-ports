--- common_m4/api_deps.m4.orig	2012-04-16 18:59:44 UTC
+++ common_m4/api_deps.m4
@@ -55,7 +55,7 @@ LIBS="$LIBCONFIG_LIBS $LIBS"
 #          [AC_MSG_ERROR("curl header file not found")]
 #     )
 
-PKG_CHECK_MODULES([JSON], [json >= 0.9])
+PKG_CHECK_MODULES([JSON], [json-c >= 0.9])
 
 CFLAGS="$JSON_CFLAGS $CFLAGS"
 LIBS="$JSON_LIBS $LIBS"
