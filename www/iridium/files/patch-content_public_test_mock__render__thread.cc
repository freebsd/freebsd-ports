--- content/public/test/mock_render_thread.cc.orig	2019-12-16 21:51:26 UTC
+++ content/public/test/mock_render_thread.cc
@@ -73,7 +73,7 @@ class MockRenderMessageFilterImpl : public mojom::Rend
     std::move(callback).Run(false);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(int32_t platform_thread_id,
                          base::ThreadPriority thread_priority) override {}
 #endif
