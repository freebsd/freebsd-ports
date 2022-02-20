--- chrome/utility/services.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/utility/services.cc
@@ -65,7 +65,7 @@
 #include "chrome/services/file_util/file_util_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD))
 #include "chrome/services/file_util/document_analysis_service.h"  // nogncheck
 #endif
 
@@ -219,7 +219,7 @@ auto RunCupsIppParser(
 }
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD))
 auto RunDocumentAnalysis(
     mojo::PendingReceiver<chrome::mojom::DocumentAnalysisService> receiver) {
   return std::make_unique<DocumentAnalysisService>(std::move(receiver));
@@ -383,7 +383,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunFileUtil);
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD))
   services.Add(RunDocumentAnalysis);
 #endif
 
