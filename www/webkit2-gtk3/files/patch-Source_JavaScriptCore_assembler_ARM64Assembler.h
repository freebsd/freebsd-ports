--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2021-09-22 23:05:58 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2950,6 +2950,8 @@ class ARM64Assembler { (public)
     {
 #if OS(DARWIN)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
