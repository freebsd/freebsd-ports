--- ui/views/controls/prefix_selector.h.orig	2021-12-16 15:23:32 UTC
+++ ui/views/controls/prefix_selector.h
@@ -81,7 +81,7 @@ class VIEWS_EXPORT PrefixSelector : public ui::TextInp
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
