--- common.mk.orig	2016-01-17 11:49:59.217894060 +0100
+++ common.mk	2016-01-17 11:50:27.299328924 +0100
@@ -49,7 +49,7 @@
 CC_COMPILE_FLAGS=$(COMPILE_FLAGS)
 
 LINK_FLAGS=${GCC_FLAGS} ${DEBUG_FLAGS} \
-	-lutil
+	-lutil -lboost_system
 
 ifeq (${UNAME_S},OpenBSD)
 LINK_FLAGS+=-liconv
