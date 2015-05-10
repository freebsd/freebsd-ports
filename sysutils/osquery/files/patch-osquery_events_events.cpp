--- osquery/events/events.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/events/events.cpp
@@ -407,6 +407,8 @@ void EventFactory::delay() {
 }
 
 Status EventFactory::run(EventPublisherID& type_id) {
+  auto& ef = EventFactory::getInstance();
+
   // An interesting take on an event dispatched entrypoint.
   // There is little introspection into the event type.
   // Assume it can either make use of an entrypoint poller/selector or
@@ -414,12 +416,17 @@ Status EventFactory::run(EventPublisherI
   // only once and handle event queueing/firing in callbacks.
   EventPublisherRef publisher;
   try {
-    publisher = EventFactory::getInstance().getEventPublisher(type_id);
+    publisher = ef.getEventPublisher(type_id);
   } catch (std::out_of_range& e) {
     return Status(1, "No event type found");
   }
 
-  VLOG(1) << "Starting event publisher runloop: " + type_id;
+  if (publisher == nullptr) {
+    return Status(1, "Event publisher is missing");
+  } else if (publisher->hasStarted()) {
+    return Status(1, "Cannot restart an event publisher");
+  }
+  VLOG(1) << "Starting event publisher run loop: " + type_id;
   publisher->hasStarted(true);
 
   auto status = Status(0, "OK");
@@ -428,11 +435,12 @@ Status EventFactory::run(EventPublisherI
     status = publisher->run();
     osquery::publisherSleep(EVENTS_COOLOFF);
   }
-
   // The runloop status is not reflective of the event type's.
-  publisher->tearDown();
   VLOG(1) << "Event publisher " << publisher->type()
-          << " runloop terminated for reason: " << status.getMessage();
+          << " run loop terminated for reason: " << status.getMessage();
+  // Publishers auto tear down when their run loop stops.
+  publisher->tearDown();
+  ef.event_pubs_.erase(type_id);
   return Status(0, "OK");
 }
 
@@ -573,9 +581,12 @@ Status EventFactory::deregisterEventPubl
     // If a publisher's run loop was not started, call tearDown since
     // the setUp happened at publisher registration time.
     publisher->tearDown();
+    // If the run loop did run the tear down and erase will happen in the event
+    // thread wrapper when isEnding is next checked.
+    ef.event_pubs_.erase(type_id);
+  } else {
+    publisher->end();
   }
-
-  ef.event_pubs_.erase(type_id);
   return Status(0, "OK");
 }
 
@@ -612,6 +623,7 @@ void EventFactory::end(bool join) {
     }
   }
 
+  // A small cool off helps OS API event publisher flushing.
   ::usleep(400);
   ef.threads_.clear();
 }
