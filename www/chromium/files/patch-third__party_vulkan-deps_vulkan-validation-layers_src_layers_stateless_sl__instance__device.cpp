--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/stateless/sl_instance_device.cpp.orig	2023-07-16 15:47:57 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/stateless/sl_instance_device.cpp
@@ -46,12 +46,12 @@ bool StatelessValidation::ValidateApiVersion(uint32_t 
             skip |= LogError(instance, "VUID-VkApplicationInfo-apiVersion-04010",
                              "Invalid CreateInstance->pCreateInfo->pApplicationInfo.apiVersion number (0x%08x). "
                              "Using VK_API_VERSION_%" PRIu32 "_%" PRIu32 ".",
-                             api_version, effective_api_version.major(), effective_api_version.minor());
+                             api_version, effective_api_version.vk_major(), effective_api_version.vk_minor());
         } else {
             skip |= LogWarning(instance, kVUIDUndefined,
                                "Unrecognized CreateInstance->pCreateInfo->pApplicationInfo.apiVersion number (0x%08x). "
                                "Assuming VK_API_VERSION_%" PRIu32 "_%" PRIu32 ".",
-                               api_version, effective_api_version.major(), effective_api_version.minor());
+                               api_version, effective_api_version.vk_major(), effective_api_version.vk_minor());
         }
     }
     return skip;
