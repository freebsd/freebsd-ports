--- extensions/renderer/bindings/argument_spec.cc.orig	2022-12-02 17:56:32 UTC
+++ extensions/renderer/bindings/argument_spec.cc
@@ -18,6 +18,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
