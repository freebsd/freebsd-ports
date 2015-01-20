--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2015-01-19 21:25:28.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARMAssembler.h	2015-01-19 21:25:57.000000000 +0000
@@ -1121,6 +1121,8 @@ namespace JSC {
             linuxPageFlush(current, end);
 #elif OS(WINCE)
             CacheRangeFlush(code, size, CACHE_SYNC_ALL);
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
