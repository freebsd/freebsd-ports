--- src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.h.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.h
@@ -67,7 +67,7 @@ class DummyTextInputClient : public TextInputClient {
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
