--- extensions/renderer/bindings/argument_spec.cc.orig	2026-11-19 12:25:27 UTC
+++ extensions/renderer/bindings/argument_spec.cc
@@ -20,6 +20,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
