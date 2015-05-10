--- osquery/dispatcher/dispatcher.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/dispatcher/dispatcher.cpp
@@ -30,13 +30,19 @@ void interruptableSleep(size_t milli) {
 Dispatcher::Dispatcher() {
   thread_manager_ = InternalThreadManager::newSimpleThreadManager(
           (size_t)FLAGS_worker_threads, 0);
-  auto threadFactory = ThriftThreadFactory(new PosixThreadFactory());
-  thread_manager_->threadFactory(threadFactory);
+  auto thread_factory = ThriftThreadFactory(new PosixThreadFactory());
+  thread_manager_->threadFactory(thread_factory);
   thread_manager_->start();
 }
 
+Dispatcher::~Dispatcher() { join(); }
+
 Status Dispatcher::add(ThriftInternalRunnableRef task) {
+  auto& self = instance();
   try {
+    if (self.state() != InternalThreadManager::STARTED) {
+      self.thread_manager_->start();
+    }
     instance().thread_manager_->add(task, 0, 0);
   } catch (std::exception& e) {
     return Status(1, e.what());
@@ -61,7 +67,12 @@ InternalThreadManagerRef Dispatcher::get
   return instance().thread_manager_;
 }
 
-void Dispatcher::join() { instance().thread_manager_->join(); }
+void Dispatcher::join() {
+  if (instance().thread_manager_ != nullptr) {
+    instance().thread_manager_->stop();
+    instance().thread_manager_->join();
+  }
+}
 
 void Dispatcher::joinServices() {
   for (auto& thread : instance().service_threads_) {
@@ -69,11 +80,11 @@ void Dispatcher::joinServices() {
   }
 }
 
-void Dispatcher::removeServices() {
+void Dispatcher::stopServices() {
   auto& self = instance();
   for (const auto& service : self.services_) {
     while (true) {
-      // Wait for each thread's entry point (enter) meaning the thread context
+      // Wait for each thread's entry point (start) meaning the thread context
       // was allocated and (run) was called by boost::thread started.
       if (service->hasRun()) {
         break;
@@ -82,15 +93,12 @@ void Dispatcher::removeServices() {
       // the boost::thread is created.
       ::usleep(200);
     }
+    service->stop();
   }
 
   for (auto& thread : self.service_threads_) {
     thread->interrupt();
   }
-
-  // Deallocate services.
-  self.service_threads_.clear();
-  self.services_.clear();
 }
 
 InternalThreadManager::STATE Dispatcher::state() const {
