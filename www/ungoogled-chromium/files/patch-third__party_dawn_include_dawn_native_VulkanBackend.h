--- third_party/dawn/include/dawn/native/VulkanBackend.h.orig	2024-05-23 20:04:36 UTC
+++ third_party/dawn/include/dawn/native/VulkanBackend.h
@@ -90,7 +90,7 @@ struct DAWN_NATIVE_EXPORT SamplerYCbCrVulkanDescriptor
 };
 
 // Can't use DAWN_PLATFORM_IS(LINUX) since header included in both Dawn and Chrome
-#ifdef __linux__
+#if defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 
 // Common properties of external images represented by FDs. On successful import the file
 // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
