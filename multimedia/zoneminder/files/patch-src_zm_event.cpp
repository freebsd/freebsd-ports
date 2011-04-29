--- src/zm_event.cpp.orig	2009-05-08 17:47:19.000000000 +0400
+++ src/zm_event.cpp	2011-04-08 17:48:07.355808702 +0400
@@ -27,6 +27,7 @@
 #include <getopt.h>
 #include <arpa/inet.h>
 #include <glob.h>
+#include <time.h>
 
 #include "zm.h"
 #include "zm_db.h"
@@ -61,8 +62,10 @@ Event::Event( Monitor *p_monitor, struct
     createNotes( notes );
 
     static char sql[BUFSIZ];
+    static char start_time_str[32];
 
     struct tm *stime = localtime( &start_time.tv_sec );
+    strftime( start_time_str, sizeof(start_time_str), "%Y-%m-%d %H:%M:%S", localtime((time_t *) &start_time.tv_sec ) );
     snprintf( sql, sizeof(sql), "insert into Events ( MonitorId, Name, StartTime, Width, Height, Cause, Notes ) values ( %d, 'New Event', from_unixtime( %ld ), %d, %d, '%s', '%s' )", monitor->Id(), start_time.tv_sec, monitor->Width(), monitor->Height(), cause.c_str(), notes.c_str() );
     if ( mysql_query( &dbconn, sql ) )
     {
@@ -150,11 +153,13 @@ Event::Event( Monitor *p_monitor, struct
 
 Event::~Event()
 {
+	static char end_time_str[32];
     if ( frames > last_db_frame )
     {
         struct DeltaTimeval delta_time;
         DELTA_TIMEVAL( delta_time, end_time, start_time, DT_PREC_2 );
 
+	strftime( end_time_str, sizeof(end_time_str), "%Y-%m-%d %H:%M:%S", localtime( (time_t *) &end_time.tv_sec ) );
         Debug( 1, "Adding closing frame %d to DB", frames );
         static char sql[BUFSIZ];
         snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, TimeStamp, Delta ) values ( %d, %d, from_unixtime( %ld ), %s%ld.%02ld )", id, frames, end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
@@ -607,7 +612,7 @@ void Event::AddFrame( Image *image, stru
     }
 }
 
-bool EventStream::loadInitialEventData( int monitor_id, time_t event_time )
+bool EventStream::loadInitialEventData( int monitor_id, long event_time )
 {
     static char sql[BUFSIZ];
 
