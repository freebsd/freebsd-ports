--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2018-02-19 07:45:14 UTC
+++ Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -1202,6 +1202,8 @@ namespace JSC {
                 linuxPageFlush(current, current + page);
 
             linuxPageFlush(current, end);
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+            __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
