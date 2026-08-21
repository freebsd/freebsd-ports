--- src/3rdparty/chromium/services/device/public/cpp/device_features.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/services/device/public/cpp/device_features.cc
@@ -197,7 +197,7 @@ BASE_FEATURE(kAutomaticUsbDetach,
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_DISABLED_BY_DEFAULT);
