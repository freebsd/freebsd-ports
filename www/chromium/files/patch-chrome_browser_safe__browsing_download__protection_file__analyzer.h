--- chrome/browser/safe_browsing/download_protection/file_analyzer.h.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/safe_browsing/download_protection/file_analyzer.h
@@ -18,7 +18,7 @@
 #include "components/safe_browsing/core/common/proto/csd.pb.h"
 #include "third_party/protobuf/src/google/protobuf/repeated_field.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/services/file_util/public/cpp/sandboxed_document_analyzer.h"
 #endif
 
@@ -110,7 +110,7 @@ class FileAnalyzer {
       const safe_browsing::ArchiveAnalyzerResults& archive_results);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   void StartExtractDocumentFeatures();
   void OnDocumentAnalysisFinished(
       const DocumentAnalyzerResults& document_results);
@@ -141,7 +141,7 @@ class FileAnalyzer {
       dmg_analyzer_{nullptr, base::OnTaskRunnerDeleter(nullptr)};
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<SandboxedDocumentAnalyzer, base::OnTaskRunnerDeleter>
       document_analyzer_{nullptr, base::OnTaskRunnerDeleter(nullptr)};
   base::TimeTicks document_analysis_start_time_;
