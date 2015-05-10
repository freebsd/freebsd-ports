--- osquery/events/darwin/fsevents.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/events/darwin/fsevents.cpp
@@ -137,6 +137,8 @@ Status FSEventsEventPublisher::run() {
   return Status(0, "OK");
 }
 
+void FSEventsEventPublisher::end() { stop(); }
+
 void FSEventsEventPublisher::Callback(
     ConstFSEventStreamRef stream,
     void* callback_info,
