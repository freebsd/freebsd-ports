--- src/3rdparty/chromium/extensions/renderer/bindings/argument_spec.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/extensions/renderer/bindings/argument_spec.cc
@@ -18,6 +18,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
