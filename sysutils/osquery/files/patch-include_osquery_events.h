--- include/osquery/events.h.orig	2015-05-05 00:16:41 UTC
+++ include/osquery/events.h
@@ -197,8 +197,8 @@ class EventPublisherPlugin : public Plug
    * @brief Perform handle opening, OS API callback registration.
    *
    * `setUp` is the event framework's EventPublisher constructor equivalent.
-   * When `setUp` is called the EventPublisher is running in a dedicated thread
-   * and may manage/allocate/wait for resources.
+   * This is called in the main thread before the publisher's run loop has
+   * started, immediately following registration.
    */
   virtual Status setUp() { return Status(0, "Not used"); }
 
@@ -206,17 +206,28 @@ class EventPublisherPlugin : public Plug
    * @brief Perform handle closing, resource cleanup.
    *
    * osquery is about to end, the EventPublisher should close handle descriptors
-   * unblock resources, and prepare to exit.
+   * unblock resources, and prepare to exit. This will be called from the main
+   * thread after the run loop thread has exited.
    */
   virtual void tearDown() {}
 
   /**
-   * @brief Implement a step of an optional run loop.
+   * @brief Implement a "step" of an optional run loop.
    *
    * @return A SUCCESS status will immediately call `run` again. A FAILED status
    * will exit the run loop and the thread.
    */
-  virtual Status run() { return Status(1, "No runloop required"); }
+  virtual Status run() { return Status(1, "No run loop required"); }
+
+  /**
+   * @brief Allow the EventFactory to interrupt the run loop.
+   *
+   * Assume the main thread may ask the run loop to stop at anytime.
+   * Before end is called the publisher's `isEnding` is set and the EventFactory
+   * run loop manager will exit the stepping loop and fall through to a call
+   * to tearDown followed by a removal of the publisher.
+   */
+  virtual void end() {}
 
   /**
    * @brief A new EventSubscriber is subscriptioning events of this
@@ -260,9 +271,16 @@ class EventPublisherPlugin : public Plug
   /// Return a string identifier associated with this EventPublisher.
   virtual EventPublisherID type() const { return "publisher"; }
 
+  /// Check if the EventFactory is ending all publisher threads.
   bool isEnding() const { return ending_; }
+
+  /// Set the ending status for this publisher.
   void isEnding(bool ending) { ending_ = ending; }
+
+  /// Check if the publisher's run loop has started.
   bool hasStarted() const { return started_; }
+
+  /// Set the run or started status for this publisher.
   void hasStarted(bool started) { started_ = started; }
 
  protected:
@@ -284,6 +302,7 @@ class EventPublisherPlugin : public Plug
  private:
   /// Set ending to True to cause event type run loops to finish.
   bool ending_;
+
   /// Set to indicate whether the event run loop ever started.
   bool started_;
 
@@ -661,11 +680,14 @@ class EventFactory : private boost::nonc
   }
 
   /**
-   * @brief Halt the EventPublisher run loop and call its `tearDown`.
+   * @brief Halt the EventPublisher run loop.
    *
    * Any EventSubscriber%s with Subscription%s for this EventPublisher will
    * become useless. osquery callers MUST deregister events.
    * EventPublisher%s assume they can hook/trampoline, which requires cleanup.
+   * This will tear down and remove the publisher if the run loop did not start.
+   * Otherwise it will call end on the publisher and assume the run loop will
+   * tear down and remove.
    *
    * @param event_pub The string label for the EventPublisher.
    *
@@ -681,6 +703,8 @@ class EventFactory : private boost::nonc
 
   /// Return an instance to a registered EventSubscriber.
   static EventSubscriberRef getEventSubscriber(EventSubscriberID& sub);
+
+  /// Check if an event subscriber exists.
   static bool exists(EventSubscriberID& sub);
 
   static std::vector<std::string> publisherTypes();
@@ -701,9 +725,12 @@ class EventFactory : private boost::nonc
   }
 
   /**
-   * @brief End all EventPublisher run loops and call their `tearDown` methods.
+   * @brief End all EventPublisher run loops and deregister.
    *
-   * End is NOT the same as deregistration.
+   * End is NOT the same as deregistration. End will call deregister on all
+   * publishers then either join or detach their run loop threads.
+   * See EventFactory::deregisterEventPublisher for actions taken during
+   * deregistration.
    *
    * @param should_end Reset the "is ending" state if False.
    */
