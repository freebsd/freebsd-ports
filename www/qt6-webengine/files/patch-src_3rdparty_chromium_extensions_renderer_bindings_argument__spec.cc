--- src/3rdparty/chromium/extensions/renderer/bindings/argument_spec.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/extensions/renderer/bindings/argument_spec.cc
@@ -18,6 +18,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
