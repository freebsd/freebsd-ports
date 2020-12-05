--- pdf/pdfium/pdfium_engine.cc.orig	2020-11-13 06:36:46 UTC
+++ pdf/pdfium/pdfium_engine.cc
@@ -69,7 +69,7 @@
 #include "ui/gfx/geometry/vector2d.h"
 #include "v8/include/v8.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "pdf/pdfium/pdfium_font_linux.h"
 #endif
 
@@ -416,7 +416,7 @@ void InitializeSDK(bool enable_v8) {
 
   FPDF_InitLibraryWithConfig(&config);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   InitializeLinuxFontMapper();
 #endif
 
@@ -475,7 +475,7 @@ PDFiumEngine::PDFiumEngine(PDFEngine::Client* client,
   IFSDK_PAUSE::user = nullptr;
   IFSDK_PAUSE::NeedToPauseNow = Pause_NeedToPauseNow;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // PreviewModeClient does not know its pp::Instance.
   SetLastInstance(client_->GetPluginInstance());
 #endif
@@ -948,7 +948,7 @@ pp::Buffer_Dev PDFiumEngine::PrintPagesAsRasterPdf(
 
   KillFormFocus();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   SetLastInstance(client_->GetPluginInstance());
 #endif
 
@@ -3042,7 +3042,7 @@ bool PDFiumEngine::ContinuePaint(int progressive_index
   DCHECK_LT(static_cast<size_t>(progressive_index), progressive_paints_.size());
 
   last_progressive_start_time_ = base::Time::Now();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   SetLastInstance(client_->GetPluginInstance());
 #endif
 
@@ -3529,7 +3529,7 @@ void PDFiumEngine::SetCurrentPage(int index) {
     FORM_DoPageAAction(old_page, form(), FPDFPAGE_AACTION_CLOSE);
   }
   most_visible_page_ = index;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   SetLastInstance(client_->GetPluginInstance());
 #endif
   if (most_visible_page_ != -1 && called_do_document_action_) {
