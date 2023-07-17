--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/utils/vk_layer_utils.h.orig	2023-07-16 15:47:57 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/utils/vk_layer_utils.h
@@ -69,7 +69,7 @@ static inline std::string StringAPIVersion(APIVersion 
     if (!version.valid()) {
         return "<unrecognized>";
     }
-    version_name << version.major() << "." << version.minor() << "." << version.patch() << " (0x" << std::setfill('0')
+    version_name << version.vk_major() << "." << version.vk_minor() << "." << version.vk_patch() << " (0x" << std::setfill('0')
                  << std::setw(8) << std::hex << version.value() << ")";
     return version_name.str();
 }
