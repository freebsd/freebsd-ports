--- src/3rdparty/chromium/ui/views/controls/prefix_selector.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/views/controls/prefix_selector.h
@@ -83,7 +83,7 @@ class VIEWS_EXPORT PrefixSelector : public ui::TextInp
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
