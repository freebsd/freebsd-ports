--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2015-08-06 08:21:27 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2862,6 +2862,8 @@ public:
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
