--- third_party/blink/renderer/core/clipboard/system_clipboard.cc.orig	2021-01-18 21:29:04 UTC
+++ third_party/blink/renderer/core/clipboard/system_clipboard.cc
@@ -42,10 +42,10 @@ SystemClipboard::SystemClipboard(LocalFrame* frame)
   frame->GetBrowserInterfaceBroker().GetInterface(
       clipboard_.BindNewPipeAndPassReceiver(
           frame->GetTaskRunner(TaskType::kUserInteraction)));
-#if defined(OS_LINUX) || BUILDFLAG(IS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_LACROS) || defined(OS_BSD)
   is_selection_buffer_available_ =
       frame->GetSettings()->GetSelectionClipboardBufferAvailable();
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_LACROS) || defined(OS_BSD)
 }
 
 bool SystemClipboard::IsSelectionMode() const {
