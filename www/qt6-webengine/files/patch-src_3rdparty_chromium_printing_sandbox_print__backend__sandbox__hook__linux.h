--- src/3rdparty/chromium/printing/sandbox/print_backend_sandbox_hook_linux.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/printing/sandbox/print_backend_sandbox_hook_linux.h
@@ -5,8 +5,13 @@
 #ifndef PRINTING_SANDBOX_PRINT_BACKEND_SANDBOX_HOOK_LINUX_H_
 #define PRINTING_SANDBOX_PRINT_BACKEND_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
 #include "base/component_export.h"
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace printing {
 
