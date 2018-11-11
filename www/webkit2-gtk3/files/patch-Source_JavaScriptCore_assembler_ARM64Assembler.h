--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2018-08-21 16:06:10 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2863,6 +2863,8 @@ class ARM64Assembler { (public)
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
