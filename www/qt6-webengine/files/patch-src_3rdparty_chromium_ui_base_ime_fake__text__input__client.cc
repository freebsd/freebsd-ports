--- src/3rdparty/chromium/ui/base/ime/fake_text_input_client.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/base/ime/fake_text_input_client.cc
@@ -161,7 +161,7 @@ bool FakeTextInputClient::ShouldDoLearning() {
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool FakeTextInputClient::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
