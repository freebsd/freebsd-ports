--- chrome/browser/safe_browsing/download_protection/file_analyzer.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/safe_browsing/download_protection/file_analyzer.cc
@@ -20,7 +20,7 @@
 #include "components/safe_browsing/core/common/features.h"
 #include "content/public/browser/browser_thread.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) | BUILDFLAG(IS_BSD)
 #include "chrome/browser/safe_browsing/download_protection/document_analysis_service.h"
 #endif
 
@@ -101,7 +101,7 @@ void FileAnalyzer::Start(const base::FilePath& target_
   } else if (inspection_type == DownloadFileType::DMG) {
     StartExtractDmgFeatures();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (base::FeatureList::IsEnabled(
                  safe_browsing::kClientSideDetectionDocumentScanning) &&
              inspection_type == DownloadFileType::OFFICE_DOCUMENT) {
@@ -285,7 +285,7 @@ void FileAnalyzer::OnDmgAnalysisFinished(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void FileAnalyzer::StartExtractDocumentFeatures() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
 
