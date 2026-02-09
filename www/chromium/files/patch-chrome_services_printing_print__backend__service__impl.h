--- chrome/services/printing/print_backend_service_impl.h.orig	2026-02-11 09:05:39 UTC
+++ chrome/services/printing/print_backend_service_impl.h
@@ -35,7 +35,7 @@
 #include "mojo/public/cpp/bindings/remote.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_context_linux.h"
 #endif
 
@@ -270,7 +270,7 @@ class PrintBackendServiceImpl : public mojom::PrintBac
 
   scoped_refptr<PrintBackend> print_backend_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PrintingContextLinux::PrintDialogFactory>
       print_dialog_factory_;
 #endif
