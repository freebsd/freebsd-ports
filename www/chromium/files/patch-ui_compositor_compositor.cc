--- ui/compositor/compositor.cc.orig	2021-01-18 21:29:48 UTC
+++ ui/compositor/compositor.cc
@@ -732,7 +732,7 @@ void Compositor::CancelThroughtputTracker(TrackerId tr
   throughput_tracker_map_.erase(tracker_id);
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   for (auto& observer : observer_list_)
     observer.OnCompositingCompleteSwapWithNewSize(this, size);
