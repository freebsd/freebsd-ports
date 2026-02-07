--- src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.cc
@@ -175,7 +175,7 @@ bool DummyTextInputClient::ShouldDoLearning() {
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool DummyTextInputClient::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
