--- Modules/Mk/ov.module.mk.orig	Tue Feb 14 00:18:29 2006
+++ Modules/Mk/ov.module.mk	Tue Feb 14 13:55:40 2006
@@ -178,7 +178,7 @@
 
 GCC=/usr/bin/gcc 
 GPP=/usr/bin/g++
-LIBTOOL=$(shell ../Mk/find-libtool.pl)
+# LIBTOOL=$(shell ../Mk/find-libtool.pl)
 
 
 ifeq ("$(OS_COMPILE)", "Darwin")
