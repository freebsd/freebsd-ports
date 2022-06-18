--- third_party/blink/renderer/platform/graphics/begin_frame_provider.cc.orig	2022-06-17 14:20:10 UTC
+++ third_party/blink/renderer/platform/graphics/begin_frame_provider.cc
@@ -76,7 +76,11 @@ void BeginFrameProvider::CreateCompositorFrameSinkIfNe
 
   // Once we are using RAF, this thread is driving Display updates. Update
   // priority accordingly.
+  // pledge(2)
+  // stop this baloney
+#if !defined(OS_OPENBSD)
   base::PlatformThread::SetCurrentThreadPriority(base::ThreadPriority::DISPLAY);
+#endif
 
   mojo::Remote<mojom::blink::EmbeddedFrameSinkProvider> provider;
   Platform::Current()->GetBrowserInterfaceBroker()->GetInterface(
