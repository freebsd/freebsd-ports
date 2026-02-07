--- build/top.mk.orig	2021-07-27 17:44:47 UTC
+++ build/top.mk
@@ -60,8 +60,6 @@ INSTALL_PROGRAM = $(INSTALL)
 INSTALL_DATA = $(INSTALL) -m 644
 INSTALL_SCRIPT = $(INSTALL)
 
-STRIP_OPTS = -s
-
 LINT = lint
 5LINT = 5lint
 
