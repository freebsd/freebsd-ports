--- Source/JavaScriptCore/assembler/ARMv7Assembler.h.orig	2021-09-22 23:05:58 UTC
+++ Source/JavaScriptCore/assembler/ARMv7Assembler.h
@@ -2402,6 +2402,8 @@ class ARMv7Assembler { (public)
     {
 #if OS(DARWIN)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
