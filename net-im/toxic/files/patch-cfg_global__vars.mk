--- cfg/global_vars.mk.orig	2017-05-24 18:57:32 UTC
+++ cfg/global_vars.mk
@@ -1,11 +1,11 @@
 # Version
-TOXIC_VERSION = 0.7.2
-REV = $(shell git rev-list HEAD --count 2>/dev/null || echo -n "error")
-ifneq (, $(findstring error, $(REV)))
+TOXIC_VERSION = 0.8.0
+#REV = $(shell git rev-list HEAD --count 2>/dev/null || echo -n "error")
+#ifneq (, $(findstring error, $(REV)))
     VERSION = $(TOXIC_VERSION)
-else
-    VERSION = $(TOXIC_VERSION)_r$(REV)
-endif
+#else
+#    VERSION = $(TOXIC_VERSION)_r$(REV)
+#endif
 
 # Project directories
 BUILD_DIR = $(BASE_DIR)/build
