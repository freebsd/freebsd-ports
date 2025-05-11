--- xbmc/windowing/gbm/drm/DRMAtomic.cpp.orig	2024-11-21 22:28:38 UTC
+++ xbmc/windowing/gbm/drm/DRMAtomic.cpp
@@ -114,7 +114,6 @@ void CDRMAtomic::DrmAtomicCommit(int fb_id, int flags,
     if (m_inFenceFd != -1)
     {
       AddProperty(m_crtc, "OUT_FENCE_PTR", reinterpret_cast<uint64_t>(&m_outFenceFd));
-      AddProperty(m_gui_plane, "IN_FENCE_FD", m_inFenceFd);
     }
   }
   else if (videoLayer && !CServiceBroker::GetGUI()->GetWindowManager().HasVisibleControls())
