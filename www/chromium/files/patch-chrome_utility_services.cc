--- chrome/utility/services.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/utility/services.cc
@@ -77,7 +77,7 @@
 #include "chrome/services/file_util/file_util_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
 #include "chrome/services/file_util/document_analysis_service.h"  // nogncheck
 #endif
 
@@ -261,7 +261,7 @@ auto RunCupsIppParser(
 }
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
 auto RunDocumentAnalysis(
     mojo::PendingReceiver<chrome::mojom::DocumentAnalysisService> receiver) {
   return std::make_unique<DocumentAnalysisService>(std::move(receiver));
@@ -454,7 +454,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunFileUtil);
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   services.Add(RunDocumentAnalysis);
 #endif
 
