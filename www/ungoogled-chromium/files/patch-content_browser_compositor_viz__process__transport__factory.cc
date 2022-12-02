--- content/browser/compositor/viz_process_transport_factory.cc.orig	2022-12-02 17:56:32 UTC
+++ content/browser/compositor/viz_process_transport_factory.cc
@@ -118,7 +118,7 @@ class HostDisplayClient : public viz::HostDisplayClien
   // viz::HostDisplayClient:
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override {
     compositor_->OnCompleteSwapWithNewSize(size);
   }
