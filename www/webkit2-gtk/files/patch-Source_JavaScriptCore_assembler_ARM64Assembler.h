--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2025-02-15 11:00:04 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -3688,6 +3688,8 @@ class ARM64Assembler { (public)
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
