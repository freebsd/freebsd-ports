--- v8/src/wasm/wasm-result.h.orig	2017-05-02 19:04:10 UTC
+++ v8/src/wasm/wasm-result.h
@@ -5,6 +5,7 @@
 #ifndef V8_WASM_RESULT_H_
 #define V8_WASM_RESULT_H_
 
+#include <cstdarg>
 #include <memory>
 
 #include "src/base/compiler-specific.h"
