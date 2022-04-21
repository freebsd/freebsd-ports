--- content/browser/renderer_host/render_frame_host_impl.h.orig	2022-04-21 18:48:31 UTC
+++ content/browser/renderer_host/render_frame_host_impl.h
@@ -3314,7 +3314,7 @@ class CONTENT_EXPORT RenderFrameHostImpl
   perfetto::protos::pbzero::RenderFrameHost::LifecycleState
   LifecycleStateToProto();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void RunScreenAIAnnotator();
 #endif
 
@@ -4154,7 +4154,7 @@ class CONTENT_EXPORT RenderFrameHostImpl
   BackForwardCacheDisablingFeaturesCallback
       back_forward_cache_disabling_features_callback_for_testing_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Manages the snapshot processing by Screen AI, if enabled.
   std::unique_ptr<AXScreenAIAnnotator> ax_screen_ai_annotator_;
 #endif
