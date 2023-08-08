--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/vulkan/generated/vk_extension_helper.h.orig	2023-07-16 15:47:57 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/vulkan/generated/vk_extension_helper.h
@@ -68,9 +68,9 @@ class APIVersion {
 
     bool valid() const { return api_version_ != VVL_UNRECOGNIZED_API_VERSION; }
     uint32_t value() const { return api_version_; }
-    uint32_t major() const { return VK_API_VERSION_MAJOR(api_version_); }
-    uint32_t minor() const { return VK_API_VERSION_MINOR(api_version_); }
-    uint32_t patch() const { return VK_API_VERSION_PATCH(api_version_); }
+    uint32_t vk_major() const { return VK_API_VERSION_MAJOR(api_version_); }
+    uint32_t vk_minor() const { return VK_API_VERSION_MINOR(api_version_); }
+    uint32_t vk_patch() const { return VK_API_VERSION_PATCH(api_version_); }
 
     bool operator<(APIVersion api_version) const { return api_version_ < api_version.api_version_; }
     bool operator<=(APIVersion api_version) const { return api_version_ <= api_version.api_version_; }
