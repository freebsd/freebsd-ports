--- content/public/test/mock_render_thread.cc.orig	2022-07-22 17:30:31 UTC
+++ content/public/test/mock_render_thread.cc
@@ -63,7 +63,7 @@ class MockRenderMessageFilterImpl : public mojom::Rend
     std::move(callback).Run(false);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void SetThreadPriority(int32_t platform_thread_id,
                          base::ThreadPriority thread_priority) override {}
 #endif
