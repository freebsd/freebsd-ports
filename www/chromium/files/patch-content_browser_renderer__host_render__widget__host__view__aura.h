--- content/browser/renderer_host/render_widget_host_view_aura.h.orig	2022-02-07 13:39:41 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.h
@@ -235,7 +235,7 @@ class CONTENT_EXPORT RenderWidgetHostViewAura
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
