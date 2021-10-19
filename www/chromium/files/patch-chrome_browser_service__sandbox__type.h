--- chrome/browser/service_sandbox_type.h.orig	2021-09-14 01:51:51 UTC
+++ chrome/browser/service_sandbox_type.h
@@ -11,8 +11,8 @@
 #include "printing/buildflags/buildflags.h"
 #include "sandbox/policy/sandbox_type.h"
 
-#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-     defined(OS_CHROMEOS)) &&                                   \
+#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
+     defined(OS_CHROMEOS)) &&                                                      \
     BUILDFLAG(ENABLE_PRINTING)
 #include "chrome/browser/printing/print_backend_service_manager.h"
 #endif
@@ -173,8 +173,8 @@ content::GetServiceSandboxType<printing::mojom::Printi
 #endif  // BUILDFLAG(ENABLE_PRINT_PREVIEW)
 
 // printing::mojom::PrintBackendService
-#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-     defined(OS_CHROMEOS)) &&                                   \
+#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
+     defined(OS_CHROMEOS)) &&                                                      \
     BUILDFLAG(ENABLE_PRINTING)
 namespace printing {
 namespace mojom {
@@ -190,7 +190,7 @@ content::GetServiceSandboxType<printing::mojom::PrintB
              ? sandbox::policy::SandboxType::kPrintBackend
              : sandbox::policy::SandboxType::kNoSandbox;
 }
-#endif  // (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         //  defined(OS_CHROMEOS)) &&
         // BUILDFLAG(ENABLE_PRINTING)
 
