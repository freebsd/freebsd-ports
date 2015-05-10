--- osquery/core/watcher.h.orig	2015-05-05 00:16:41 UTC
+++ osquery/core/watcher.h
@@ -210,7 +210,7 @@ class WatcherRunner : public InternalRun
 
  private:
   /// Dispatcher (this service thread's) entry point.
-  void enter();
+  void start();
   /// Boilerplate function to sleep for some configured latency
   bool ok();
   /// Begin the worker-watcher process.
@@ -239,7 +239,7 @@ class WatcherRunner : public InternalRun
 class WatcherWatcherRunner : public InternalRunnable {
  public:
   explicit WatcherWatcherRunner(pid_t watcher) : watcher_(watcher) {}
-  void enter();
+  void start();
 
  private:
   pid_t watcher_;
