--- chrome/browser/new_tab_page/modules/drive/drive_service.cc.orig	2021-09-24 18:25:14 UTC
+++ chrome/browser/new_tab_page/modules/drive/drive_service.cc
@@ -36,6 +36,8 @@ constexpr char kPlatform[] = "WINDOWS";
 constexpr char kPlatform[] = "MAC_OS";
 #elif OS_CHROMEOS
 constexpr char kPlatform[] = "CHROME_OS";
+#elif OS_FREEBSD
+constexpr char kPlatform[] = "FREEBSD";
 #else
 constexpr char kPlatform[] = "UNSPECIFIED_PLATFORM";
 #endif
