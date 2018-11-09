--- config.mk.orig	2018-09-25 15:27:43 UTC
+++ config.mk
@@ -275,7 +275,7 @@ ifeq ($(WITH_WEBSOCKETS),static)
 endif
 
 INSTALL?=install
-prefix?=/usr/local
+prefix?=${PREFIX}
 incdir?=${prefix}/include
 libdir?=${prefix}/lib${LIB_SUFFIX}
 localedir?=${prefix}/share/locale
