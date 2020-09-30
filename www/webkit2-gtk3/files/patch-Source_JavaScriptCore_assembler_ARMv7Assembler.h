--- Source/JavaScriptCore/assembler/ARMv7Assembler.h.orig	2020-08-12 09:17:52 UTC
+++ Source/JavaScriptCore/assembler/ARMv7Assembler.h
@@ -2396,6 +2396,8 @@ class ARMv7Assembler { (public)
     {
 #if OS(DARWIN)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
