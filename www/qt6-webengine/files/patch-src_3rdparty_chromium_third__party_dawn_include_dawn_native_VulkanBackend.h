--- src/3rdparty/chromium/third_party/dawn/include/dawn/native/VulkanBackend.h.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/third_party/dawn/include/dawn/native/VulkanBackend.h
@@ -82,7 +82,7 @@ struct ExternalImageExportInfoVk : ExternalImageExport
 };
 
 // Can't use DAWN_PLATFORM_IS(LINUX) since header included in both Dawn and Chrome
-#ifdef __linux__
+#if defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 
 // Common properties of external images represented by FDs. On successful import the file
 // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
