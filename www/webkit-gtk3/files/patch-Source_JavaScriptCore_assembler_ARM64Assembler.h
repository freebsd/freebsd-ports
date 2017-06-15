--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2016-04-10 06:48:36 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2756,6 +2756,8 @@ public:
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
