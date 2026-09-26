--- ui/ozone/platform/wayland/host/wayland_frame_manager.cc.orig	2026-09-25 15:26:43 UTC
+++ ui/ozone/platform/wayland/host/wayland_frame_manager.cc
@@ -5,7 +5,9 @@
 #include "ui/ozone/platform/wayland/host/wayland_frame_manager.h"
 
 #include <presentation-time-client-protocol.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sync/sync.h>
+#endif
 
 #include <cstdint>
 #include <variant>
@@ -490,8 +492,10 @@ std::optional<bool> WaylandFrameManager::ApplySurfaceC
   surface->UpdateBufferDamageRegion(
       gfx::ToEnclosingRectIgnoringError(surface_damage));
 
+#if !BUILDFLAG(IS_BSD)
   if (!config.access_fence_handle.is_null())
     surface->set_acquire_fence(std::move(config.access_fence_handle));
+#endif
 
   bool needs_commit = false;
 
@@ -523,6 +527,9 @@ std::optional<bool> WaylandFrameManager::ApplySurfaceC
       case WaylandBufferHandle::SyncMethod::kNone:
         break;
       case WaylandBufferHandle::SyncMethod::kSyncobj:
+#if BUILDFLAG(IS_BSD)
+        LOG(WARNING) << "WaylandBufferHandle::SyncMethod::kSyncobj is not supported!";
+#endif
         surface->RequestExplicitRelease(
             base::BindOnce(&WaylandFrameManager::OnExplicitBufferRelease,
                            weak_factory_.GetWeakPtr(), surface));
@@ -530,6 +537,9 @@ std::optional<bool> WaylandFrameManager::ApplySurfaceC
       case WaylandBufferHandle::SyncMethod::kDMAFence:
         [[fallthrough]];
       case WaylandBufferHandle::SyncMethod::kImplicit:
+#if BUILDFLAG(IS_BSD)
+        LOG(WARNING) << "WaylandBufferHandle::SyncMethod::kSyncobj is not supported!";
+#endif
         buffer_handle->set_buffer_released_callback(
             base::BindOnce(&WaylandFrameManager::OnWlBufferRelease,
                            weak_factory_.GetWeakPtr(), surface),
@@ -788,8 +798,10 @@ void WaylandFrameManager::OnExplicitBufferRelease(Wayl
 
       if (fence.is_valid()) {
         if (frame->merged_release_fence_fd.is_valid()) {
+#if !BUILDFLAG(IS_BSD)
           frame->merged_release_fence_fd.reset(sync_merge(
               "", frame->merged_release_fence_fd.get(), fence.get()));
+#endif
         } else {
           frame->merged_release_fence_fd = std::move(fence);
         }
@@ -827,8 +839,10 @@ void WaylandFrameManager::OnWlBufferRelease(WaylandSur
 
         if (fence.is_valid()) {
           if (frame->merged_release_fence_fd.is_valid()) {
+#if !BUILDFLAG(IS_BSD)
             frame->merged_release_fence_fd.reset(sync_merge(
                 "", frame->merged_release_fence_fd.get(), fence.get()));
+#endif
           } else {
             frame->merged_release_fence_fd = std::move(fence);
           }
