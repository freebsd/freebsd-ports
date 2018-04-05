--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2018-03-05 09:28:05 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2856,6 +2856,8 @@ class ARM64Assembler { (public)
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
