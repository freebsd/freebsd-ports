--- ui/base/clipboard/clipboard_non_backed.cc.orig	2026-11-17 21:17:00 UTC
+++ ui/base/clipboard/clipboard_non_backed.cc
@@ -472,7 +472,7 @@ ClipboardNonBacked::ClipboardNonBacked() {
   // so create internal clipboards for platform supported clipboard buffers.
   constexpr ClipboardBuffer kClipboardBuffers[] = {
       ClipboardBuffer::kCopyPaste,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
       ClipboardBuffer::kSelection,
 #endif
 #if BUILDFLAG(IS_MAC)
