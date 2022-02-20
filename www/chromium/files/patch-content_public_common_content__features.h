--- content/public/common/content_features.h.orig	2022-02-07 13:39:41 UTC
+++ content/public/common/content_features.h
@@ -248,7 +248,7 @@ CONTENT_EXPORT extern const base::Feature
 CONTENT_EXPORT extern const base::Feature kWebAppWindowControlsOverlay;
 CONTENT_EXPORT extern const base::Feature kWebAssemblyBaseline;
 CONTENT_EXPORT extern const base::Feature kWebAssemblyCodeProtection;
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 CONTENT_EXPORT extern const base::Feature kWebAssemblyCodeProtectionPku;
 #endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) &&
         // defined(ARCH_CPU_X86_64)
@@ -306,7 +306,7 @@ CONTENT_EXPORT extern const base::Feature kMacSyscallS
 CONTENT_EXPORT extern const base::Feature kRetryGetVideoCaptureDeviceInfos;
 #endif  // defined(OS_MAC)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 CONTENT_EXPORT extern const base::Feature kSendWebUIJavaScriptErrorReports;
 CONTENT_EXPORT extern const char
     kSendWebUIJavaScriptErrorReportsSendToProductionVariation[];
