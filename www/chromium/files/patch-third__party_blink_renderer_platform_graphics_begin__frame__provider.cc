--- third_party/blink/renderer/platform/graphics/begin_frame_provider.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/blink/renderer/platform/graphics/begin_frame_provider.cc
@@ -74,7 +74,11 @@ void BeginFrameProvider::CreateCompositorFrameSinkIfNe
 
   // Once we are using RAF, this thread is driving Display updates. Update
   // priority accordingly.
+  // pledge(2)
+  // stop this baloney
+#if !defined(OS_OPENBSD)
   base::PlatformThread::SetCurrentThreadPriority(base::ThreadPriority::DISPLAY);
+#endif
 
   mojo::Remote<mojom::blink::EmbeddedFrameSinkProvider> provider;
   Platform::Current()->GetBrowserInterfaceBroker()->GetInterface(
