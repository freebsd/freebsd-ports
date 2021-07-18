--- third_party/blink/renderer/core/clipboard/system_clipboard.cc.orig	2021-04-14 18:41:09 UTC
+++ third_party/blink/renderer/core/clipboard/system_clipboard.cc
@@ -43,10 +43,10 @@ SystemClipboard::SystemClipboard(LocalFrame* frame)
   frame->GetBrowserInterfaceBroker().GetInterface(
       clipboard_.BindNewPipeAndPassReceiver(
           frame->GetTaskRunner(TaskType::kUserInteraction)));
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   is_selection_buffer_available_ =
       frame->GetSettings()->GetSelectionClipboardBufferAvailable();
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 }
 
 bool SystemClipboard::IsSelectionMode() const {
