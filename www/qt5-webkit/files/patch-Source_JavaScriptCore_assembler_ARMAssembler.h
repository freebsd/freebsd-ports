armv6/v7: cacheFlush support
See PR 222612

--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2017-08-23 05:02:37 UTC
+++ Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -1128,6 +1128,8 @@ namespace JSC {
                 linuxPageFlush(current, current + page);
 
             linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
