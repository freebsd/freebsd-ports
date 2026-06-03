--- src/3rdparty/chromium/services/device/public/cpp/device_features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/services/device/public/cpp/device_features.cc
@@ -147,7 +147,7 @@ BASE_FEATURE(kAutomaticUsbDetach,
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_DISABLED_BY_DEFAULT);
