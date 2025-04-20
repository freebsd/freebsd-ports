--- src/lib/geogram/lua/lua_io.cpp.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/lua/lua_io.cpp
@@ -237,6 +237,8 @@ namespace {
 	    const char* result = "unknown";
 #if defined(GEO_OS_LINUX)
 	    result = "Linux";
+#elif defined(GEO_OS_FREEBSD)
+	    result = "FreeBSD";
 #elif defined(GEO_OS_APPLE)
 	    result = "Apple";
 #elif defined(GEO_OS_WINDOWS)
