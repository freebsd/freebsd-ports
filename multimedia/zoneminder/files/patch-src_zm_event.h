--- src/zm_event.h.orig	2009-03-20 15:07:00.000000000 +0300
+++ src/zm_event.h	2011-04-08 17:48:07.357806760 +0400
@@ -228,7 +228,7 @@ protected:
 protected:
     bool loadEventData( int event_id );
     bool loadInitialEventData( int init_event_id, int init_frame_id );
-    bool loadInitialEventData( int monitor_id, time_t event_time );
+    bool loadInitialEventData( int monitor_id, long event_time );
 
     void checkEventLoaded();
     void processCommand( const CmdMsg *msg );
@@ -251,7 +251,7 @@ public:
         loadInitialEventData( init_event_id, init_frame_id );
         loadMonitor( event_data->monitor_id );
     }
-	void setStreamStart( int monitor_id, time_t event_time )
+	void setStreamStart( int monitor_id, long event_time )
     {
         loadInitialEventData( monitor_id, event_time );
         loadMonitor( monitor_id );
