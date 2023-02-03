Index: Source/JavaScriptCore/assembler/ARM64Assembler.h
--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2918,6 +2918,8 @@ class ARM64Assembler { (public)
     {
 #if OS(DARWIN)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
