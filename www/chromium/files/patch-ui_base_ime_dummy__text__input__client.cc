--- ui/base/ime/dummy_text_input_client.cc.orig	2021-12-16 15:20:13 UTC
+++ ui/base/ime/dummy_text_input_client.cc
@@ -155,7 +155,7 @@ bool DummyTextInputClient::ShouldDoLearning() {
   return false;
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool DummyTextInputClient::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
