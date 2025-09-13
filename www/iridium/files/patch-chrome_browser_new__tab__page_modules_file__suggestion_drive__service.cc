--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -36,7 +36,7 @@
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
