--- Source/JavaScriptCore/assembler/ARMv7Assembler.h.orig	2019-02-12 11:21:03 UTC
+++ Source/JavaScriptCore/assembler/ARMv7Assembler.h
@@ -2471,6 +2471,8 @@ class ARMv7Assembler { (public)
     {
 #if OS(IOS_FAMILY)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
