--- pdf/pdfium/pdfium_engine.cc.orig	2017-06-05 19:03:10 UTC
+++ pdf/pdfium/pdfium_engine.cc
@@ -129,7 +129,7 @@ std::vector<uint32_t> GetPageNumbersFromPrintPageNumbe
   return page_numbers;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 PP_Instance g_last_instance_id;
 
@@ -642,7 +642,7 @@ bool InitializeSDK() {
   config.m_v8EmbedderSlot = gin::kEmbedderPDFium;
   FPDF_InitLibraryWithConfig(&config);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Font loading doesn't work in the renderer sandbox in Linux.
   FPDF_SetSystemFontInfo(&g_font_info);
 #else
@@ -667,7 +667,7 @@ bool InitializeSDK() {
 
 void ShutdownSDK() {
   FPDF_DestroyLibrary();
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   delete g_font_info;
 #endif
   TearDownV8();
@@ -772,7 +772,7 @@ PDFiumEngine::PDFiumEngine(PDFEngine::Client* client)
   IFSDK_PAUSE::user = nullptr;
   IFSDK_PAUSE::NeedToPauseNow = Pause_NeedToPauseNow;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // PreviewModeClient does not know its pp::Instance.
   pp::Instance* instance = client_->GetPluginInstance();
   if (instance)
@@ -1516,7 +1516,7 @@ pp::Buffer_Dev PDFiumEngine::PrintPagesAsRasterPDF(
     FPDF_ClosePage(pdf_page);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   g_last_instance_id = client_->GetPluginInstance()->pp_instance();
 #endif
 
@@ -2953,7 +2953,7 @@ bool PDFiumEngine::ContinuePaint(int progressive_index
   DCHECK_LT(static_cast<size_t>(progressive_index), progressive_paints_.size());
   DCHECK(image_data);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   g_last_instance_id = client_->GetPluginInstance()->pp_instance();
 #endif
 
@@ -3411,7 +3411,7 @@ void PDFiumEngine::SetCurrentPage(int index) {
     FORM_DoPageAAction(old_page, form_, FPDFPAGE_AACTION_CLOSE);
   }
   most_visible_page_ = index;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     g_last_instance_id = client_->GetPluginInstance()->pp_instance();
 #endif
   if (most_visible_page_ != -1 && called_do_document_action_) {
