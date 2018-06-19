--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2018-05-28 10:30:34 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2683,6 +2683,8 @@ class ARM64Assembler { (public)
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
