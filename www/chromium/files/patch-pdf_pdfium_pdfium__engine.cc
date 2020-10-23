--- pdf/pdfium/pdfium_engine.cc.orig	2020-09-08 19:14:08 UTC
+++ pdf/pdfium/pdfium_engine.cc
@@ -58,7 +58,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "v8/include/v8.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "pdf/pdfium/pdfium_font_linux.h"
 #endif
 
@@ -396,7 +396,7 @@ void InitializeSDK(bool enable_v8) {
   config.m_v8EmbedderSlot = gin::kEmbedderPDFium;
   FPDF_InitLibraryWithConfig(&config);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   InitializeLinuxFontMapper();
 #endif
 
@@ -437,7 +437,7 @@ PDFiumEngine::PDFiumEngine(PDFEngine::Client* client, 
   IFSDK_PAUSE::user = nullptr;
   IFSDK_PAUSE::NeedToPauseNow = Pause_NeedToPauseNow;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // PreviewModeClient does not know its pp::Instance.
   SetLastInstance(client_->GetPluginInstance());
 #endif
@@ -913,7 +913,7 @@ pp::Buffer_Dev PDFiumEngine::PrintPagesAsRasterPdf(
 
   KillFormFocus();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SetLastInstance(client_->GetPluginInstance());
 #endif
 
@@ -2960,7 +2960,7 @@ bool PDFiumEngine::ContinuePaint(int progressive_index
   DCHECK(image_data);
 
   last_progressive_start_time_ = base::Time::Now();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SetLastInstance(client_->GetPluginInstance());
 #endif
 
@@ -3456,7 +3456,7 @@ void PDFiumEngine::SetCurrentPage(int index) {
     FORM_DoPageAAction(old_page, form(), FPDFPAGE_AACTION_CLOSE);
   }
   most_visible_page_ = index;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SetLastInstance(client_->GetPluginInstance());
 #endif
   if (most_visible_page_ != -1 && called_do_document_action_) {
