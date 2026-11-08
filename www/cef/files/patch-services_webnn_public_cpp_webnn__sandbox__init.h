--- services/webnn/public/cpp/webnn_sandbox_init.h.orig	2026-08-31 10:59:09 UTC
+++ services/webnn/public/cpp/webnn_sandbox_init.h
@@ -10,7 +10,7 @@
 
 namespace webnn {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Preloads WebNN LiteRT libraries (like the GPU accelerator DLL) before the
 // GPU process sandbox is locked down.
 COMPONENT_EXPORT(WEBNN_PUBLIC_CPP)
