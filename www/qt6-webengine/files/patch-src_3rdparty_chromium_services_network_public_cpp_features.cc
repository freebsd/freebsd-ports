--- src/3rdparty/chromium/services/network/public/cpp/features.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/services/network/public/cpp/features.cc
@@ -383,7 +383,7 @@ CONSTINIT const base::Feature kOutOfProcessSystemDnsRe
 // that can be adequately sandboxed.
 CONSTINIT const base::Feature kOutOfProcessSystemDnsResolution(
              "OutOfProcessSystemDnsResolution",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
