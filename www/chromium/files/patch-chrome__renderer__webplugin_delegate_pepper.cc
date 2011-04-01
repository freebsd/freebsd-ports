--- ./chrome/renderer/webplugin_delegate_pepper.cc.orig	2010-12-16 02:11:59.000000000 +0100
+++ ./chrome/renderer/webplugin_delegate_pepper.cc	2010-12-20 20:15:08.000000000 +0100
@@ -9,7 +9,7 @@
 #include <string>
 #include <vector>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include <unistd.h>
 #endif
 
@@ -39,7 +39,7 @@
 #include "chrome/renderer/pepper_widget.h"
 #include "chrome/renderer/render_thread.h"
 #include "chrome/renderer/render_view.h"
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/renderer/renderer_sandbox_support_linux.h"
 #endif
 #include "chrome/renderer/webplugin_delegate_proxy.h"
@@ -463,7 +463,7 @@
 NPError NPMatchFontWithFallback(NPP instance,
                                 const NPFontDescription* description,
                                 NPFontID* id) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   int fd = renderer_sandbox_support::MatchFontWithFallback(
       description->face, description->weight >= 700, description->italic,
       description->charset);
@@ -482,7 +482,7 @@
                      uint32_t table,
                      void* output,
                      size_t* output_length) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   bool rv = renderer_sandbox_support::GetFontTable(
       id, table, static_cast<uint8_t*>(output), output_length);
   return rv ? NPERR_NO_ERROR : NPERR_GENERIC_ERROR;
@@ -493,7 +493,7 @@
 }
 
 NPError NPDestroyFont(NPP instance, NPFontID id) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   close(id);
   return NPERR_NO_ERROR;
 #else
@@ -1169,10 +1169,10 @@
       current_printer_dpi_ = printer_dpi;
     }
   }
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   num_pages_ = num_pages;
   pdf_output_done_ = false;
-#endif  // (OS_LINUX)
+#endif  // OS_LINUX || OS_FREEBSD
   return num_pages;
 }
 
@@ -1198,7 +1198,7 @@
   unsigned char* pdf_output = NULL;
   int32 output_size = 0;
   NPPrintPageNumberRange page_range;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // On Linux we will try and output all pages as PDF in the first call to
   // PrintPage. This is a temporary hack.
   // TODO(sanjeevr): Remove this hack and fix this by changing the print
@@ -1207,9 +1207,9 @@
     return pdf_output_done_;
   page_range.firstPageNumber = 0;
   page_range.lastPageNumber = num_pages_ - 1;
-#else  // defined(OS_LINUX)
+#else  // defined(OS_LINUX) || defined(OS_FREEBSD)
   page_range.firstPageNumber = page_range.lastPageNumber = page_number;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
   NPError err = print_extensions->printPagesAsPDF(instance()->npp(),
                                                   &page_range, 1,
                                                   &pdf_output, &output_size);
@@ -1217,7 +1217,7 @@
     return false;
 
   bool ret = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // On Linux we need to get the backing PdfPsMetafile and write the bits
   // directly.
   cairo_t* context = canvas->beginPlatformPaint();
@@ -1370,10 +1370,10 @@
   current_printer_dpi_ = -1;
 #if defined(OS_MACOSX)
   last_printed_page_ = SkBitmap();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   num_pages_ = 0;
   pdf_output_done_ = false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 }
 
 WebPluginDelegatePepper::WebPluginDelegatePepper(
@@ -1384,10 +1384,10 @@
       instance_(instance),
       nested_delegate_(NULL),
       current_printer_dpi_(-1),
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       num_pages_(0),
       pdf_output_done_(false),
-#endif  // (OS_LINUX)
+#endif  // OS_LINUX || OS_FREEBSD
 #if defined(ENABLE_GPU)
       command_buffer_(NULL),
       method_factory3d_(ALLOW_THIS_IN_INITIALIZER_LIST(this)),
