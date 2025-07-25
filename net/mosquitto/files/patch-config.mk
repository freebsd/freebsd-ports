--- config.mk.orig	2025-07-11 21:32:27 UTC
+++ config.mk
@@ -347,7 +347,7 @@ INSTALL?=install
 endif
 
 INSTALL?=install
-prefix?=/usr/local
+prefix?=${PREFIX}
 incdir?=${prefix}/include
 libdir?=${prefix}/lib${LIB_SUFFIX}
 localedir?=${prefix}/share/locale
