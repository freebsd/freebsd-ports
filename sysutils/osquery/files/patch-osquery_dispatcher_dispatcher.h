--- osquery/dispatcher/dispatcher.h.orig	2015-05-05 00:16:41 UTC
+++ osquery/dispatcher/dispatcher.h
@@ -31,8 +31,12 @@
 
 namespace osquery {
 
+using namespace apache::thrift::concurrency;
+
+/// Create easier to reference typedefs for Thrift layer implementations.
+#define SHARED_PTR_IMPL OSQUERY_THRIFT_POINTER::shared_ptr
 typedef apache::thrift::concurrency::ThreadManager InternalThreadManager;
-typedef OSQUERY_THRIFT_POINTER::shared_ptr<InternalThreadManager> InternalThreadManagerRef;
+typedef SHARED_PTR_IMPL<InternalThreadManager> InternalThreadManagerRef;
 
 /**
  * @brief Default number of threads in the thread pool.
@@ -42,7 +46,7 @@ typedef OSQUERY_THRIFT_POINTER::shared_p
  */
 extern const int kDefaultThreadPoolSize;
 
-class InternalRunnable : public apache::thrift::concurrency::Runnable {
+class InternalRunnable : public Runnable {
  public:
   virtual ~InternalRunnable() {}
   InternalRunnable() : run_(false) {}
@@ -51,16 +55,20 @@ class InternalRunnable : public apache::
   /// The boost::thread entrypoint.
   void run() {
     run_ = true;
-    enter();
+    start();
   }
 
   /// Check if the thread's entrypoint (run) executed, meaning thread context
   /// was allocated.
   bool hasRun() { return run_; }
 
+  /// The runnable may also tear down services before the thread context
+  /// is removed.
+  virtual void stop() {}
+
  protected:
   /// Require the runnable thread define an entrypoint.
-  virtual void enter() = 0;
+  virtual void start() = 0;
 
  private:
   bool run_;
@@ -70,9 +78,8 @@ class InternalRunnable : public apache::
 typedef std::shared_ptr<InternalRunnable> InternalRunnableRef;
 typedef std::shared_ptr<boost::thread> InternalThreadRef;
 /// A thrift internal runnable with variable pointer wrapping.
-typedef OSQUERY_THRIFT_POINTER::shared_ptr<InternalRunnable> ThriftInternalRunnableRef;
-typedef OSQUERY_THRIFT_POINTER::shared_ptr<
-    apache::thrift::concurrency::PosixThreadFactory> ThriftThreadFactory;
+typedef SHARED_PTR_IMPL<InternalRunnable> ThriftInternalRunnableRef;
+typedef SHARED_PTR_IMPL<PosixThreadFactory> ThriftThreadFactory;
 
 /**
  * @brief Singleton for queueing asynchronous tasks to be executed in parallel
@@ -160,7 +167,7 @@ class Dispatcher : private boost::noncop
   static void joinServices();
 
   /// Destroy and stop all osquery service threads and service objects.
-  static void removeServices();
+  static void stopServices();
 
   /**
    * @brief Get the current state of the thread manager.
@@ -248,7 +255,7 @@ class Dispatcher : private boost::noncop
   Dispatcher();
   Dispatcher(Dispatcher const&);
   void operator=(Dispatcher const&);
-  virtual ~Dispatcher() {}
+  virtual ~Dispatcher();
 
  private:
   /**
@@ -262,10 +269,15 @@ class Dispatcher : private boost::noncop
    * @see getThreadManager
    */
   InternalThreadManagerRef thread_manager_;
+
   /// The set of shared osquery service threads.
   std::vector<InternalThreadRef> service_threads_;
-  /// THe set of shared osquery services.
+
+  /// The set of shared osquery services.
   std::vector<InternalRunnableRef> services_;
+
+ private:
+  friend class ExtensionsTest;
 };
 
 /// Allow a dispatched thread to wait while processing or to prevent thrashing.
