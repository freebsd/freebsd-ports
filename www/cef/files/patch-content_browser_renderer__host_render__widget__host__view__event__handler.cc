--- content/browser/renderer_host/render_widget_host_view_event_handler.cc.orig	2026-09-24 17:21:42 UTC
+++ content/browser/renderer_host/render_widget_host_view_event_handler.cc
@@ -53,7 +53,7 @@ namespace {
 // of the border area, in percentage of the corresponding dimension.
 const int kMouseLockBorderPercentage = 15;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/aura/window_tree_host.h"
 #endif
 
@@ -635,7 +635,7 @@ bool RenderWidgetHostViewEventHandler::C
   if (event->type() == ui::EventType::kMouseExited) {
     if (mouse_locked || selection_popup)
       return false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Don't forward the mouse leave message which is received when the context
     // menu is displayed by the page. This confuses the page and causes state
     // changes.
@@ -863,7 +863,7 @@ void RenderWidgetHostViewEventHandler::M
     return;
   }
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (host_view_->HasExternalParent() &&
       window_ && window_->delegate()->CanFocus()) {
     aura::WindowTreeHost* host = window_->GetHost();
