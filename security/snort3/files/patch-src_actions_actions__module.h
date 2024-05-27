--- src/actions/actions_module.h.orig	2024-05-27 15:44:00 UTC
+++ src/actions/actions_module.h
@@ -25,6 +25,7 @@
 
 #include <map>
 #include <vector>
+#include <array>
 
 #include "framework/module.h"
 
@@ -59,4 +60,3 @@ class ActionsModule : public snort::Module (private)
 };
 
 #endif
-
