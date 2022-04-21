--- chrome/utility/services.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/utility/services.cc
@@ -28,7 +28,7 @@
 #include "printing/buildflags/buildflags.h"
 #include "ui/accessibility/accessibility_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/screen_ai/screen_ai_service_impl.h"
 #endif
 
@@ -67,7 +67,7 @@
 #include "chrome/services/file_util/file_util_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
 #include "chrome/services/file_util/document_analysis_service.h"  // nogncheck
 #endif
 
@@ -213,7 +213,7 @@ auto RunSpeechRecognitionService(
 }
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 auto RunScreenAIService(
     mojo::PendingReceiver<screen_ai::mojom::ScreenAIService> receiver) {
   return std::make_unique<screen_ai::ScreenAIService>(std::move(receiver));
@@ -227,7 +227,7 @@ auto RunCupsIppParser(
 }
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
 auto RunDocumentAnalysis(
     mojo::PendingReceiver<chrome::mojom::DocumentAnalysisService> receiver) {
   return std::make_unique<DocumentAnalysisService>(std::move(receiver));
@@ -374,7 +374,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunSpeechRecognitionService);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (features::IsScreenAIEnabled())
     services.Add(RunScreenAIService);
 #endif
@@ -398,7 +398,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunFileUtil);
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   services.Add(RunDocumentAnalysis);
 #endif
 
