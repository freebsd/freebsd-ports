--- src/3rdparty/chromium/v8/src/wasm/wasm-result.h.orig	2017-12-15 19:26:27.709014000 -0500
+++ src/3rdparty/chromium/v8/src/wasm/wasm-result.h	2017-12-15 19:26:41.537495000 -0500
@@ -5,6 +5,7 @@
 #ifndef V8_WASM_RESULT_H_
 #define V8_WASM_RESULT_H_
 
+#include <cstdarg>
 #include <memory>
 
 #include "src/base/compiler-specific.h"
