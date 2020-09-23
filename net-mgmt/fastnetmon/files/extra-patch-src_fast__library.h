--- src/fast_library.h.orig	2020-09-23 17:00:00 UTC
+++ src/fast_library.h
@@ -25,7 +25,7 @@
 #include "libpatricia/patricia.h"
 
 #ifdef ENABLE_LUA_HOOKS
-#include <luajit-2.0/lua.hpp>
+#include <luajit-2.1/lua.hpp>
 #endif
 
 #define TCP_FIN_FLAG_SHIFT 1
