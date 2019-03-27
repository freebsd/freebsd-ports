--- src/3rdparty/chromium/pdf/pdfium/pdfium_engine.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/pdf/pdfium/pdfium_engine.cc
@@ -137,7 +137,7 @@ constexpr bool kIsEditModeTracked = false;
 
 PDFiumEngine* g_engine_for_fontmapper = nullptr;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 PP_Instance g_last_instance_id;
 
@@ -641,7 +641,7 @@ bool InitializeSDK() {
   config.m_v8EmbedderSlot = gin::kEmbedderPDFium;
   FPDF_InitLibraryWithConfig(&config);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Font loading doesn't work in the renderer sandbox in Linux.
   FPDF_SetSystemFontInfo(&g_font_info);
 #else
@@ -666,7 +666,7 @@ bool InitializeSDK() {
 
 void ShutdownSDK() {
   FPDF_DestroyLibrary();
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   delete g_font_info;
 #endif
   TearDownV8();
@@ -690,7 +690,7 @@ PDFiumEngine::PDFiumEngine(PDFEngine::Client* client, 
   IFSDK_PAUSE::user = nullptr;
   IFSDK_PAUSE::NeedToPauseNow = Pause_NeedToPauseNow;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // PreviewModeClient does not know its pp::Instance.
   pp::Instance* instance = client_->GetPluginInstance();
   if (instance)
@@ -1147,7 +1147,7 @@ pp::Buffer_Dev PDFiumEngine::PrintPagesAsRasterPDF(
 
   KillFormFocus();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   g_last_instance_id = client_->GetPluginInstance()->pp_instance();
 #endif
 
@@ -2842,7 +2842,7 @@ bool PDFiumEngine::ContinuePaint(int progressive_index
   DCHECK(image_data);
 
   last_progressive_start_time_ = base::Time::Now();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   g_last_instance_id = client_->GetPluginInstance()->pp_instance();
 #endif
 
@@ -3320,7 +3320,7 @@ void PDFiumEngine::SetCurrentPage(int index) {
     FORM_DoPageAAction(old_page, form(), FPDFPAGE_AACTION_CLOSE);
   }
   most_visible_page_ = index;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   g_last_instance_id = client_->GetPluginInstance()->pp_instance();
 #endif
   if (most_visible_page_ != -1 && called_do_document_action_) {
