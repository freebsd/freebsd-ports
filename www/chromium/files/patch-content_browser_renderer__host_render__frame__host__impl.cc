--- content/browser/renderer_host/render_frame_host_impl.cc.orig	2022-04-21 18:48:31 UTC
+++ content/browser/renderer_host/render_frame_host_impl.cc
@@ -272,7 +272,7 @@
 #include "content/browser/renderer_host/render_view_host_delegate_view.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/accessibility/ax_screen_ai_annotator.h"
 #include "ui/accessibility/accessibility_features.h"
 #endif
@@ -2632,7 +2632,7 @@ void RenderFrameHostImpl::AccessibilityPerformAction(
       view->SetLastPointerType(ui::EventPointerType::kTouch);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (action_data.action == ax::mojom::Action::kRunScreenAi) {
     RunScreenAIAnnotator();
     return;
@@ -2642,7 +2642,7 @@ void RenderFrameHostImpl::AccessibilityPerformAction(
   render_accessibility_->PerformAction(action_data);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void RenderFrameHostImpl::RunScreenAIAnnotator() {
   if (!features::IsScreenAIEnabled())
     return;
