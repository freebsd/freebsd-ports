--- config.mk.orig	2026-02-04 22:33:13 UTC
+++ config.mk
@@ -180,7 +180,7 @@ INSTALL?=install
 ARCH:=$(shell uname -p)
 
 INSTALL?=install
-prefix?=/usr/local
+prefix?=${PREFIX}
 incdir?=${prefix}/include
 libdir?=${prefix}/lib${LIB_SUFFIX}
 localedir?=${prefix}/share/locale
