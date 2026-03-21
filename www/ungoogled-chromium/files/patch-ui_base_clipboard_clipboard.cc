--- ui/base/clipboard/clipboard.cc.orig	2026-03-15 18:32:51 UTC
+++ ui/base/clipboard/clipboard.cc
@@ -28,7 +28,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -78,7 +78,7 @@ bool Clipboard::IsSupportedClipboardBuffer(ClipboardBu
 
 // static
 bool Clipboard::IsMiddleClickPasteEnabled() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     return linux_ui->PrimaryPasteEnabled();
   }
