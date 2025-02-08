The signature of doEventLoop() was changed to match that of
triggerEvent(), by using std::atomic_char as the 'watch variable'
type in net/liveMedia 2024.11.28.

--- modules/access/live555.cpp.orig	2024-06-05 15:56:07 UTC
+++ modules/access/live555.cpp
@@ -236,8 +236,8 @@ struct demux_sys_t
     bool             b_no_data;     /* if we never received any data */
     int              i_no_data_ti;  /* consecutive number of TaskInterrupt */
 
-    char             event_rtsp;
-    char             event_data;
+    std::atomic_char             event_rtsp;
+    std::atomic_char             event_data;
 
     bool             b_get_param;   /* Does the server support GET_PARAMETER */
     bool             b_paused;      /* Are we paused? */
