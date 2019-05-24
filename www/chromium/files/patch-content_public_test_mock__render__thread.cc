--- content/public/test/mock_render_thread.cc.orig	2019-04-30 22:22:47 UTC
+++ content/public/test/mock_render_thread.cc
@@ -74,7 +74,7 @@ class MockRenderMessageFilterImpl : public mojom::Rend
     std::move(callback).Run(false);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(int32_t platform_thread_id,
                          base::ThreadPriority thread_priority) override {}
 #endif
