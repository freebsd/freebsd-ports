--- content/browser/browser_child_process_host_impl_receiver_bindings.cc.orig	2023-12-23 12:33:28 UTC
+++ content/browser/browser_child_process_host_impl_receiver_bindings.cc
@@ -62,7 +62,7 @@ void BrowserChildProcessHostImpl::BindHostReceiver(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto r = receiver.As<mojom::ThreadTypeSwitcher>()) {
     child_thread_type_switcher_.Bind(std::move(r));
     return;
