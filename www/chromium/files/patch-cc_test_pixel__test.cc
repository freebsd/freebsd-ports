--- cc/test/pixel_test.cc.orig	2020-07-13 09:15:14 UTC
+++ cc/test/pixel_test.cc
@@ -69,7 +69,7 @@ PixelTest::PixelTest(GraphicsBackend backend)
     init_vulkan = true;
   } else if (backend == kSkiaDawn) {
     scoped_feature_list_.InitAndEnableFeature(features::kSkiaDawn);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     init_vulkan = true;
 #elif defined(OS_WIN)
     // TODO(sgilhuly): Initialize D3D12 for Windows.
