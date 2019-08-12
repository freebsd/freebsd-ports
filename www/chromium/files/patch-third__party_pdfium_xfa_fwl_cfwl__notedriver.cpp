--- third_party/pdfium/xfa/fwl/cfwl_notedriver.cpp.orig	2019-07-29 19:41:09 UTC
+++ third_party/pdfium/xfa/fwl/cfwl_notedriver.cpp
@@ -83,14 +83,14 @@ bool CFWL_NoteDriver::SetFocus(CFWL_Widget* pFocus) {
 }
 
 void CFWL_NoteDriver::Run() {
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   for (;;) {
     CFWL_NoteLoop* pTopLoop = GetTopLoop();
     if (!pTopLoop || !pTopLoop->ContinueModal())
       break;
     UnqueueMessageAndProcess(pTopLoop);
   }
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 }
 
 void CFWL_NoteDriver::NotifyTargetHide(CFWL_Widget* pNoteTarget) {
