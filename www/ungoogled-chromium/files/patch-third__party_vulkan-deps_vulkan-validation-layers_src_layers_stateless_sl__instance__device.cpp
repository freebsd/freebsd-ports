--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/stateless/sl_instance_device.cpp.orig	2023-09-17 07:59:53 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/stateless/sl_instance_device.cpp
@@ -26,12 +26,12 @@ bool StatelessValidation::ValidateApiVersion(uint32_t 
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
