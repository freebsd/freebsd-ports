--- build/top.mk.orig	2014-09-18 18:48:49.000000000 -0700
+++ build/top.mk	2015-04-27 12:02:52.234737749 -0700
@@ -59,8 +59,6 @@
 INSTALL_DATA = $(INSTALL) -m 644
 INSTALL_SCRIPT = $(INSTALL)
 
-STRIP = -s
-
 LINT = lint
 5LINT = 5lint
 
