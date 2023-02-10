--- src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.h
@@ -63,7 +63,7 @@ class DummyTextInputClient : public TextInputClient {
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
