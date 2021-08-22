--- chrome/browser/search/drive/drive_service.cc.orig	2021-07-19 18:45:09 UTC
+++ chrome/browser/search/drive/drive_service.cc
@@ -27,6 +27,8 @@ namespace {
 constexpr char kDriveScope[] = "https://www.googleapis.com/auth/drive.readonly";
 #if OS_LINUX
 constexpr char kPlatform[] = "LINUX";
+#elif OS_FREEBSD
+constexpr char kPlatform[] = "FREEBSD";
 #elif OS_WIN
 constexpr char kPlatform[] = "WINDOWS";
 #elif OS_MAC
