--- gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc.orig	2026-07-01 06:24:19 UTC
+++ gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc
@@ -194,6 +194,7 @@ void DawnOzoneImageRepresentation::EndAccess() {
   if (!texture_) {
     return;
   }
+#if 0
   wgpu::SharedTextureMemoryEndAccessState end_access_desc = {};
   wgpu::SharedTextureMemoryVkImageLayoutEndState end_layout{};
   end_access_desc.nextInChain = &end_layout;
@@ -243,6 +244,12 @@ void DawnOzoneImageRepresentation::EndAccess() {
 
   texture_.Destroy();
   texture_ = nullptr;
+#else
+    LOG(ERROR) << "Failed to end access for DawnOzoneImageRepresentation";
+    texture_.Destroy();
+    texture_ = nullptr;
+    return;
+#endif
 }
 
 }  // namespace gpu
