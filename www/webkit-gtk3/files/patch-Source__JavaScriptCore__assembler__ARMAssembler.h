--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2014-12-15 04:13:43.336068961 +0000
+++ Source/JavaScriptCore/assembler/ARMAssembler.h	2014-12-15 04:13:49.213068201 +0000
@@ -1121,6 +1121,8 @@
             linuxPageFlush(current, end);
 #elif OS(WINCE)
             CacheRangeFlush(code, size, CACHE_SYNC_ALL);
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+            __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
