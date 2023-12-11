--- content/utility/utility_thread_impl.cc.orig	2023-12-10 06:10:27 UTC
+++ content/utility/utility_thread_impl.cc
@@ -32,7 +32,7 @@
 #include "mojo/public/cpp/bindings/service_factory.h"
 #include "third_party/abseil-cpp/absl/types/optional.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -252,7 +252,8 @@ void UtilityThreadImpl::Init() {
 
   GetContentClient()->utility()->UtilityThreadStarted();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   SandboxedProcessThreadTypeHandler::NotifyMainChildThreadCreated();
 #endif
 
