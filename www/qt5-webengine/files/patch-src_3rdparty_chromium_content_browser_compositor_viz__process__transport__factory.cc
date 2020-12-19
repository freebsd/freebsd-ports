--- src/3rdparty/chromium/content/browser/compositor/viz_process_transport_factory.cc.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/content/browser/compositor/viz_process_transport_factory.cc
@@ -109,7 +109,7 @@ class HostDisplayClient : public viz::HostDisplayClien
   HostDisplayClient& operator=(const HostDisplayClient&) = delete;
 
   // viz::HostDisplayClient:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override {
     compositor_->OnCompleteSwapWithNewSize(size);
   }
