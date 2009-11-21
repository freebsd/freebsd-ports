--- common.mk.orig	2009-11-20 00:32:31.545770710 -0800
+++ common.mk	2009-11-20 00:32:51.669545361 -0800
@@ -51,7 +51,7 @@
 LINK_FLAGS=${GCC_FLAGS} ${DEBUG_FLAGS} \
 	-lutil
 
-ifeq (${UNAME_S},OpenBSD)
+ifeq (${UNAME_S},FreeBSD)
 LINK_FLAGS+=-liconv
 endif
 
