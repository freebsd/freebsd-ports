--- cargo-crates/v8-150.4.0/v8/src/base/strings.h.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/v8/src/base/strings.h
@@ -9,6 +9,8 @@
 #include "src/base/macros.h"
 #include "src/base/vector.h"
 
+#include <cstdarg>
+
 namespace v8 {
 namespace base {
 
