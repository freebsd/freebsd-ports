--- content/browser/renderer_host/render_widget_host_view_aura.h.orig	2026-02-15 10:01:45 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.h
@@ -287,7 +287,7 @@ class CONTENT_EXPORT RenderWidgetHostViewAura
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
