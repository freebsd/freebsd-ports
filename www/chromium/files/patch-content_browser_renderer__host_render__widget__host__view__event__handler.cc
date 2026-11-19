--- content/browser/renderer_host/render_widget_host_view_event_handler.cc.orig	2026-11-19 12:25:27 UTC
+++ content/browser/renderer_host/render_widget_host_view_event_handler.cc
@@ -704,7 +704,7 @@ bool RenderWidgetHostViewEventHandler::CanRendererHand
   if (event->type() == ui::EventType::kMouseExited) {
     if (mouse_locked || selection_popup)
       return false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Don't forward the mouse leave message which is received when the context
     // menu is displayed by the page. This confuses the page and causes state
     // changes.
