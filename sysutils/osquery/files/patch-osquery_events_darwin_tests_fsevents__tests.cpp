--- osquery/events/darwin/tests/fsevents_tests.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/events/darwin/tests/fsevents_tests.cpp
@@ -25,27 +25,33 @@
 
 namespace osquery {
 
-const std::string kRealTestPath = kTestWorkingDirectory + "fsevents_trigger";
 int kMaxEventLatency = 3000;
 
 class FSEventsTests : public testing::Test {
  protected:
-  void TearDown() { boost::filesystem::remove_all(kRealTestPath); }
+  void SetUp() {
+    trigger_path = kTestWorkingDirectory + "fsevents" +
+                   std::to_string(rand() % 10000 + 10000);
+  }
+
+  void TearDown() { remove(trigger_path); }
 
   void StartEventLoop() {
     event_pub_ = std::make_shared<FSEventsEventPublisher>();
     EventFactory::registerEventPublisher(event_pub_);
-    FILE* fd = fopen(kRealTestPath.c_str(), "w");
+    FILE* fd = fopen(trigger_path.c_str(), "w");
     fclose(fd);
 
     temp_thread_ = boost::thread(EventFactory::run, "fsevents");
+    // Wait for the publisher thread and FSEvent run loop to start.
   }
 
   void EndEventLoop() {
     while (!event_pub_->hasStarted()) {
       ::usleep(20);
     }
-    EventFactory::end();
+    EventFactory::end(false);
+    temp_thread_.join();
   }
 
   void WaitForStream(int max) {
@@ -76,7 +82,7 @@ class FSEventsTests : public testing::Te
   void CreateEvents(int num = 1) {
     WaitForStream(kMaxEventLatency);
     for (int i = 0; i < num; ++i) {
-      FILE* fd = fopen(kRealTestPath.c_str(), "w");
+      FILE* fd = fopen(trigger_path.c_str(), "a");
       fputs("fsevents", fd);
       fclose(fd);
     }
@@ -84,8 +90,14 @@ class FSEventsTests : public testing::Te
 
   std::shared_ptr<FSEventsEventPublisher> event_pub_;
   boost::thread temp_thread_;
+
+ public:
+  /// Trigger path is the current test's eventing sink (accessed anywhere).
+  static std::string trigger_path;
 };
 
+std::string FSEventsTests::trigger_path = kTestWorkingDirectory + "fsevents";
+
 TEST_F(FSEventsTests, test_register_event_pub) {
   auto pub = std::make_shared<FSEventsEventPublisher>();
   auto status = EventFactory::registerEventPublisher(pub);
@@ -159,7 +171,7 @@ class TestFSEventsEventSubscriber
 
   SCRef GetSubscription(uint32_t mask = 0) {
     auto sc = createSubscriptionContext();
-    sc->path = kRealTestPath;
+    sc->path = FSEventsTests::trigger_path;
     sc->mask = mask;
     return sc;
   }
@@ -176,10 +188,10 @@ class TestFSEventsEventSubscriber
     return Status(0, "OK");
   }
 
-  void WaitForEvents(int max) {
+  void WaitForEvents(int max, int initial = 0) {
     int delay = 0;
     while (delay < max * 1000) {
-      if (callback_count_ > 0) {
+      if (callback_count_ > initial) {
         return;
       }
       ::usleep(50);
@@ -203,14 +215,17 @@ TEST_F(FSEventsTests, test_fsevents_run)
 
   // Create a subscriptioning context
   auto mc = std::make_shared<FSEventsSubscriptionContext>();
-  mc->path = kRealTestPath;
+  mc->path = trigger_path;
   EventFactory::addSubscription(
       "fsevents", Subscription::create("TestFSEventsEventSubscriber", mc));
 
   // Create an event loop thread (similar to main)
-  boost::thread temp_thread(EventFactory::run, "fsevents");
+  temp_thread_ = boost::thread(EventFactory::run, "fsevents");
   EXPECT_TRUE(event_pub_->numEvents() == 0);
 
+  // Wait for the thread to start and the FSEvents stream to turn on.
+  WaitForStream(kMaxEventLatency);
+
   // Cause an fsevents event(s) by writing to the watched path.
   CreateEvents();
 
@@ -218,7 +233,10 @@ TEST_F(FSEventsTests, test_fsevents_run)
   WaitForEvents(kMaxEventLatency);
 
   EXPECT_TRUE(event_pub_->numEvents() > 0);
-  EventFactory::end();
+
+  // We are managing the thread ourselves, so no join needed.
+  EventFactory::end(false);
+  temp_thread_.join();
 }
 
 TEST_F(FSEventsTests, test_fsevents_fire_event) {
@@ -257,10 +275,9 @@ TEST_F(FSEventsTests, test_fsevents_even
   sub->WaitForEvents(kMaxEventLatency);
 
   // Make sure the fsevents action was expected.
-  EXPECT_TRUE(sub->actions_.size() > 0);
-  if (sub->actions_.size() > 1) {
-    EXPECT_EQ(sub->actions_[0], "UPDATED");
-  }
+  ASSERT_TRUE(sub->actions_.size() > 0);
+  EXPECT_EQ(sub->actions_[0], "CREATED");
+
   EndEventLoop();
 }
 }
