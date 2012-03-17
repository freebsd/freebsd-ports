--- xbmc/pvr/PVRManager.h.orig
+++ xbmc/pvr/PVRManager.h
@@ -532,7 +532,7 @@ namespace PVR
     int                             m_LastChannel;
     unsigned int                    m_LastChannelChanged;
 
-    ManagerState                    m_managerState;
+    long                            m_managerState;
   };
 
   class CPVRRecordingsUpdateJob : public CJob
