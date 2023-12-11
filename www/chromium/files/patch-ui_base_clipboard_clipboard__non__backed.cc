--- ui/base/clipboard/clipboard_non_backed.cc.orig	2023-12-10 06:10:27 UTC
+++ ui/base/clipboard/clipboard_non_backed.cc
@@ -459,7 +459,7 @@ ClipboardNonBacked::ClipboardNonBacked() {
   // so create internal clipboards for platform supported clipboard buffers.
   constexpr ClipboardBuffer kClipboardBuffers[] = {
     ClipboardBuffer::kCopyPaste,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     ClipboardBuffer::kSelection,
 #endif
 #if BUILDFLAG(IS_MAC)
