--- ui/base/ime/dummy_text_input_client.cc.orig	2024-11-04 08:56:03 UTC
+++ ui/base/ime/dummy_text_input_client.cc
@@ -163,7 +163,7 @@ bool DummyTextInputClient::ShouldDoLearning() {
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool DummyTextInputClient::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
