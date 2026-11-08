--- source/ni_libxcoder_dynamic_loading.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_libxcoder_dynamic_loading.h
@@ -751,8 +751,10 @@ class NETINTLibxcoderAPI { (public)
         //
         // Function pointers for ni_quadraprobe.h
         //
+#if defined(__linux__)
         functionList->niRsrcLogDump = reinterpret_cast<decltype(ni_rsrc_log_dump)*>(dlsym(lib,"ni_rsrc_log_dump"));
         functionList->niRsrcNorLogCommand = reinterpret_cast<decltype(ni_rsrc_nor_log_command)*>(dlsym(lib,"ni_rsrc_nor_log_command"));
+#endif
 
     }
 };
