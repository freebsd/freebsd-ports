--- Source/JavaScriptCore/assembler/ARMAssembler.h
+++ Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -1064,6 +1064,8 @@
             linuxPageFlush(current, end);
 #elif OS(WINCE)
             CacheRangeFlush(code, size, CACHE_SYNC_ALL);
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+            __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(QNX) && ENABLE(ASSEMBLER_WX_EXCLUSIVE)
             UNUSED_PARAM(code);
             UNUSED_PARAM(size);
