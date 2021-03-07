--- config.mk.orig	2020-12-28 13:24:40 UTC
+++ config.mk
@@ -329,7 +329,7 @@ ifeq ($(WITH_WEBSOCKETS),static)
 endif
 
 INSTALL?=install
-prefix?=/usr/local
+prefix?=${PREFIX}
 incdir?=${prefix}/include
 libdir?=${prefix}/lib${LIB_SUFFIX}
 localedir?=${prefix}/share/locale
