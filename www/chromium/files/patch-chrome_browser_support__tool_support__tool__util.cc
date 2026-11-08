--- chrome/browser/support_tool/support_tool_util.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/support_tool/support_tool_util.cc
@@ -52,7 +52,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_WITH_HW_DETAILS)
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/support_tool/updater_data_collector.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -291,7 +291,7 @@ std::unique_ptr<SupportToolHandler> GetSupportToolHand
 #endif  // BUILDFLAG(IS_CHROMEOS_WITH_HW_DETAILS)
         break;
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       case support_tool::CHROME_UPDATER:
         handler->AddDataCollector(std::make_unique<UpdaterDataCollector>());
         break;
@@ -336,7 +336,7 @@ GetAllAvailableDataCollectorsOnDevice() {
   }
 #endif  // BUILDFLAG(IS_CHROMEOS_WITH_HW_DETAILS)
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   for (const auto& type : kDataCollectorsLinuxMacWin) {
     data_collectors.push_back(type);
   }
