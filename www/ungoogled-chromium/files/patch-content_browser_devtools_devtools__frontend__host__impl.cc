--- content/browser/devtools/devtools_frontend_host_impl.cc.orig	2026-05-09 18:09:27 UTC
+++ content/browser/devtools/devtools_frontend_host_impl.cc
@@ -26,7 +26,7 @@
 #include "third_party/blink/public/common/associated_interfaces/associated_interface_provider.h"
 #include "ui/base/webui/resource_path.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/content/browser/error_reporting/javascript_error_report.h"  // nogncheck
 #include "components/crash/content/browser/error_reporting/js_error_report_processor.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -38,7 +38,7 @@ const char kCompatibilityScriptSourceURL[] =
     "\n//# "
     "sourceURL=devtools://devtools/bundled/devtools_compatibility.js";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Remove the pieces of the URL we don't want to send back with the error
 // reports. In particular, do not send query or fragments as those can have
 // privacy-sensitive information in them.
@@ -134,7 +134,7 @@ void DevToolsFrontendHostImpl::DispatchEmbedderMessage
   handle_message_callback_.Run(std::move(message));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void DevToolsFrontendHostImpl::OnDidAddMessageToConsole(
     RenderFrameHost* source_frame,
     blink::mojom::ConsoleMessageLevel log_level,
