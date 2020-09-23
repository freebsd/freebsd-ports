--- src/netflow_plugin/netflow_collector.cpp.orig	2020-09-23 17:05:19 UTC
+++ src/netflow_plugin/netflow_collector.cpp
@@ -28,7 +28,7 @@
 #include "log4cpp/Priority.hh"
 
 #ifdef ENABLE_LUA_HOOKS
-#include <luajit-2.0/lua.hpp>
+#include <luajit-2.1/lua.hpp>
 #endif
 
 #ifdef ENABLE_LUA_HOOKS
