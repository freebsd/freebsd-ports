--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2024-06-25 12:08:48 UTC
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -32,7 +32,7 @@
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
