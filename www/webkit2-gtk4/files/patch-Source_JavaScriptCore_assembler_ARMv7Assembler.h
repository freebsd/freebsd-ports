Index: Source/JavaScriptCore/assembler/ARMv7Assembler.h
--- Source/JavaScriptCore/assembler/ARMv7Assembler.h.orig
+++ Source/JavaScriptCore/assembler/ARMv7Assembler.h
@@ -2573,6 +2573,8 @@ class ARMv7Assembler { (public)
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif CPU(ARM_TRADITIONAL) && (OS(FREEBSD) || OS(OPENBSD)) && COMPILER(CLANG)
+       __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
