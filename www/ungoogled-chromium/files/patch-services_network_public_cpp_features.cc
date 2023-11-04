--- services/network/public/cpp/features.cc.orig	2023-11-04 07:08:51 UTC
+++ services/network/public/cpp/features.cc
@@ -371,7 +371,7 @@ BASE_FEATURE(kPrivateNetworkAccessPermissionPrompt,
 // that can be adequately sandboxed.
 BASE_FEATURE(kOutOfProcessSystemDnsResolution,
              "OutOfProcessSystemDnsResolution",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
