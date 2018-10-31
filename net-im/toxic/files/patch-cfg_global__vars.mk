--- cfg/global_vars.mk.orig	2018-10-30 22:03:44 UTC
+++ cfg/global_vars.mk
@@ -1,11 +1,6 @@
 # Version
 TOXIC_VERSION = 0.8.3
-REV = $(shell git rev-list HEAD --count 2>/dev/null || echo -n "error")
-ifneq (, $(findstring error, $(REV)))
-    VERSION = $(TOXIC_VERSION)
-else
-    VERSION = $(TOXIC_VERSION)_r$(REV)
-endif
+#REV = $(shell git rev-list HEAD --count 2>/dev/null || echo -n "error")
 
 # Project directories
 BUILD_DIR = $(BASE_DIR)/build
