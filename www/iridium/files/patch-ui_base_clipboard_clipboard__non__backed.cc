--- ui/base/clipboard/clipboard_non_backed.cc.orig	2024-06-25 12:08:48 UTC
+++ ui/base/clipboard/clipboard_non_backed.cc
@@ -461,7 +461,7 @@ ClipboardNonBacked::ClipboardNonBacked() {
   // so create internal clipboards for platform supported clipboard buffers.
   constexpr ClipboardBuffer kClipboardBuffers[] = {
     ClipboardBuffer::kCopyPaste,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     ClipboardBuffer::kSelection,
 #endif
 #if BUILDFLAG(IS_MAC)
