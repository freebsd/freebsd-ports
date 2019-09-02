Index: config.mk
===================================================================
--- config.mk.orig
+++ config.mk
@@ -283,7 +283,7 @@ ifeq ($(WITH_WEBSOCKETS),static)
 endif
 
 INSTALL?=install
-prefix?=/usr/local
+prefix?=${PREFIX}
 incdir?=${prefix}/include
 libdir?=${prefix}/lib${LIB_SUFFIX}
 localedir?=${prefix}/share/locale
