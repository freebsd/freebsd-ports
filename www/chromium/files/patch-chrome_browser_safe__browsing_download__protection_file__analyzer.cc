--- chrome/browser/safe_browsing/download_protection/file_analyzer.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/safe_browsing/download_protection/file_analyzer.cc
@@ -19,7 +19,7 @@
 #include "components/safe_browsing/core/common/features.h"
 #include "content/public/browser/browser_thread.h"
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) | defined(OS_BSD)
 #include "chrome/browser/safe_browsing/download_protection/document_analysis_service.h"
 #endif
 
@@ -100,7 +100,7 @@ void FileAnalyzer::Start(const base::FilePath& target_
   } else if (inspection_type == DownloadFileType::DMG) {
     StartExtractDmgFeatures();
 #endif
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   } else if (base::FeatureList::IsEnabled(
                  safe_browsing::kClientSideDetectionDocumentScanning) &&
              inspection_type == DownloadFileType::OFFICE_DOCUMENT) {
@@ -284,7 +284,7 @@ void FileAnalyzer::OnDmgAnalysisFinished(
 }
 #endif  // defined(OS_MAC)
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 void FileAnalyzer::StartExtractDocumentFeatures() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
 
