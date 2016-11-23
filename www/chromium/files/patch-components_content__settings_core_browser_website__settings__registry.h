--- components/content_settings/core/browser/website_settings_registry.h.orig	2016-10-06 04:02:16.000000000 +0300
+++ components/content_settings/core/browser/website_settings_registry.h	2016-10-13 13:24:49.647706000 +0300
@@ -36,10 +36,11 @@
     PLATFORM_MAC = 1 << 3,
     PLATFORM_ANDROID = 1 << 4,
     PLATFORM_IOS = 1 << 5,
+    PLATFORM_BSD = 1 << 6,
 
     // Settings only applied to win, mac, linux and chromeos.
     DESKTOP =
-        PLATFORM_WINDOWS | PLATFORM_LINUX | PLATFORM_CHROMEOS | PLATFORM_MAC,
+        PLATFORM_WINDOWS | PLATFORM_LINUX | PLATFORM_CHROMEOS | PLATFORM_MAC | PLATFORM_BSD,
 
     // Settings applied to all platforms, including win, mac, linux, chromeos,
     // android, ios.
