--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2019-01-09 10:08:35 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2874,6 +2874,8 @@ class ARM64Assembler { (public)
     {
 #if OS(IOS_FAMILY)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
