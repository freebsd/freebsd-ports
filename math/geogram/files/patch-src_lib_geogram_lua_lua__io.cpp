--- src/lib/geogram/lua/lua_io.cpp.orig	2018-12-09 17:40:56 UTC
+++ src/lib/geogram/lua/lua_io.cpp
@@ -243,6 +243,8 @@ namespace {
 	    const char* result = "unknown";
 #if defined(GEO_OS_LINUX)
 	    result = "Linux";
+#elif defined(GEO_OS_FREEBSD)
+	    result = "FreeBSD";
 #elif defined(GEO_OS_APPLE)
 	    result = "Apple";
 #elif defined(GEO_OS_WINDOWS)
