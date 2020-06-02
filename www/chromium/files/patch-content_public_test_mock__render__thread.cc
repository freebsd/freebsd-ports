--- content/public/test/mock_render_thread.cc.orig	2020-05-13 18:40:32 UTC
+++ content/public/test/mock_render_thread.cc
@@ -51,7 +51,7 @@ class MockRenderMessageFilterImpl : public mojom::Rend
     std::move(callback).Run(false);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(int32_t platform_thread_id,
                          base::ThreadPriority thread_priority) override {}
 #endif
