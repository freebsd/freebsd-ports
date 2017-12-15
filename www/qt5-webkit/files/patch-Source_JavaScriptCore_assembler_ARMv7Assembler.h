armv6/v7: cacheFlush support
See PR 222612

--- Source/JavaScriptCore/assembler/ARMv7Assembler.h.orig	2017-08-23 04:59:46 UTC
+++ Source/JavaScriptCore/assembler/ARMv7Assembler.h
@@ -2373,6 +2373,8 @@ class ARMv7Assembler { (public)
             linuxPageFlush(current, current + page);

         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
