--- coreconf/ruleset.mk~
+++ coreconf/ruleset.mk
@@ -85,7 +85,7 @@
 #
 
 ifndef COMPILER_TAG
-    ifneq ($(DEFAULT_COMPILER), $(notdir $(firstword $(CC))))
+    ifneq ($(DEFAULT_COMPILER), $(CC))
 #
 # Temporary define for the Client; to be removed when binary release is used
 #
