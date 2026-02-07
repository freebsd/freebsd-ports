--- src/3rdparty/chromium/ui/base/ime/fake_text_input_client.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/ime/fake_text_input_client.cc
@@ -227,7 +227,7 @@ bool FakeTextInputClient::ShouldDoLearning() {
   return should_do_learning_;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool FakeTextInputClient::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
