--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -39,7 +39,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
