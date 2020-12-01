--- third_party/blink/renderer/core/clipboard/system_clipboard.cc.orig	2020-11-16 14:53:50 UTC
+++ third_party/blink/renderer/core/clipboard/system_clipboard.cc
@@ -41,10 +41,10 @@ SystemClipboard::SystemClipboard(LocalFrame* frame)
   frame->GetBrowserInterfaceBroker().GetInterface(
       clipboard_.BindNewPipeAndPassReceiver(
           frame->GetTaskRunner(TaskType::kUserInteraction)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   is_selection_buffer_available_ =
       frame->GetSettings()->GetSelectionClipboardBufferAvailable();
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 }
 
 bool SystemClipboard::IsSelectionMode() const {
