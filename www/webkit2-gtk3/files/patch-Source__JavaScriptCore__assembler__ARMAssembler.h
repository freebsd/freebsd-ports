--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2014-12-02 14:49:22.000000000 +0100
+++ Source/JavaScriptCore/assembler/ARMAssembler.h	2014-12-26 10:35:15.394821543 +0100
@@ -1104,6 +1104,8 @@
                 linuxPageFlush(current, current + page);
 
             linuxPageFlush(current, end);
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+            __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
