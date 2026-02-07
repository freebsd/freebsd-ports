--- src/3rdparty/chromium/ui/base/clipboard/clipboard_non_backed.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_non_backed.cc
@@ -461,7 +461,7 @@ ClipboardNonBacked::ClipboardNonBacked() {
   // so create internal clipboards for platform supported clipboard buffers.
   constexpr ClipboardBuffer kClipboardBuffers[] = {
     ClipboardBuffer::kCopyPaste,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     ClipboardBuffer::kSelection,
 #endif
 #if BUILDFLAG(IS_MAC)
