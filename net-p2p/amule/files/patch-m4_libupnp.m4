--- m4/libupnp.m4.orig	2016-09-16 07:55:06 UTC
+++ m4/libupnp.m4
@@ -45,11 +45,16 @@ m4_define([MIN_LIBUPNP_VERSION], [m4_ifv
 
 dnl	Test for --with-libupnp-prefix
 	AC_ARG_WITH(
-		[libupnp-prefix],
-		[AS_HELP_STRING(
+		[libupnp-prefix],[
+		AS_HELP_STRING(
 			[--with-libupnp-prefix=PREFIX],
-			[UPnP library location])],
-		[export PKG_CONFIG_PATH=$withval/lib/pkgconfig])
+			[UPnP library location])],[
+		AS_IF([test -d "$withval/lib64/pkgconfig"],[
+			export PKG_CONFIG_PATH=$withval/lib64/pkgconfig
+		],[
+			export PKG_CONFIG_PATH=$withval/lib/pkgconfig
+		])
+	])
 
 dnl	Check for libupnp >= MIN_LIBUPNP_VERSION
 	AS_IF([test $cross_compiling = no], [
