--- osquery/events/darwin/fsevents.h.orig	2015-05-05 00:16:41 UTC
+++ osquery/events/darwin/fsevents.h
@@ -76,6 +76,8 @@ class FSEventsEventPublisher
 
   // Entrypoint to the run loop
   Status run();
+  // Callin for stopping the streams/run loop.
+  void end();
 
  public:
   /// FSEvents registers a client callback instead of using a select/poll loop.
