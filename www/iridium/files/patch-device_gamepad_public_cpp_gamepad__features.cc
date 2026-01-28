--- device/gamepad/public/cpp/gamepad_features.cc.orig	2026-01-16 14:21:21 UTC
+++ device/gamepad/public/cpp/gamepad_features.cc
@@ -38,7 +38,7 @@ BASE_FEATURE(kGamepadRawInputChangeEvent, base::FEATUR
 BASE_FEATURE(kIgnorePS5GamepadsInWgi, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enabling this feature causes GamepadPlatformDataFetcherLinux to check device
 // IDs before opening the hidraw device node to avoid interfering with devices
 // that are not gamepads or do not require hidraw access.
