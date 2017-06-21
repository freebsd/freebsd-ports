--- content/browser/renderer_host/render_widget_host_view_event_handler.cc.orig	2017-06-05 19:03:07 UTC
+++ content/browser/renderer_host/render_widget_host_view_event_handler.cc
@@ -548,7 +548,7 @@ bool RenderWidgetHostViewEventHandler::CanRendererHand
   if (event->type() == ui::ET_MOUSE_EXITED) {
     if (mouse_locked || selection_popup)
       return false;
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     // Don't forward the mouse leave message which is received when the context
     // menu is displayed by the page. This confuses the page and causes state
     // changes.
