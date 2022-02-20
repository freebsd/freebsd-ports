--- chrome/browser/safe_browsing/download_protection/file_analyzer.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/safe_browsing/download_protection/file_analyzer.h
@@ -16,7 +16,7 @@
 #include "components/safe_browsing/core/common/proto/csd.pb.h"
 #include "third_party/protobuf/src/google/protobuf/repeated_field.h"
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/services/file_util/public/cpp/sandboxed_document_analyzer.h"
 #endif
 
@@ -111,7 +111,7 @@ class FileAnalyzer {
       const safe_browsing::ArchiveAnalyzerResults& archive_results);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   void StartExtractDocumentFeatures();
   void OnDocumentAnalysisFinished(
       const DocumentAnalyzerResults& document_results);
@@ -131,7 +131,7 @@ class FileAnalyzer {
   scoped_refptr<SandboxedDMGAnalyzer> dmg_analyzer_;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   scoped_refptr<SandboxedDocumentAnalyzer> document_analyzer_;
   base::TimeTicks document_analysis_start_time_;
 #endif
