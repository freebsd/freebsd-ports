--- ui/base/ime/dummy_text_input_client.h.orig	2021-12-16 15:20:25 UTC
+++ ui/base/ime/dummy_text_input_client.h
@@ -64,7 +64,7 @@ class DummyTextInputClient : public TextInputClient {
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
