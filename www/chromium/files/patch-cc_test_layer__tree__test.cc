--- cc/test/layer_tree_test.cc.orig	2020-09-08 19:13:57 UTC
+++ cc/test/layer_tree_test.cc
@@ -654,7 +654,7 @@ LayerTreeTest::LayerTreeTest(LayerTreeTest::RendererTy
     init_vulkan = true;
   } else if (renderer_type_ == RENDERER_SKIA_DAWN) {
     scoped_feature_list_.InitAndEnableFeature(features::kSkiaDawn);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     init_vulkan = true;
 #elif defined(OS_WIN)
     // TODO(sgilhuly): Initialize D3D12 for Windows.
