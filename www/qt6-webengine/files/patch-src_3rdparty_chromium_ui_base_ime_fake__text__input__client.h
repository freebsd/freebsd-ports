--- src/3rdparty/chromium/ui/base/ime/fake_text_input_client.h.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/ui/base/ime/fake_text_input_client.h
@@ -74,7 +74,7 @@ class FakeTextInputClient : public TextInputClient {
   void SetTextEditCommandForNextKeyEvent(TextEditCommand command) override;
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
