--- osquery/core/watcher.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/core/watcher.cpp
@@ -171,7 +171,7 @@ bool WatcherRunner::ok() {
   return (Watcher::getWorker() >= 0 || Watcher::hasManagedExtensions());
 }
 
-void WatcherRunner::enter() {
+void WatcherRunner::start() {
   // Set worker performance counters to an initial state.
   Watcher::resetWorkerCounters(0);
   signal(SIGCHLD, childHandler);
@@ -327,6 +327,15 @@ void WatcherRunner::createWorker() {
     setenv("OSQUERY_EXTENSIONS", "true", 1);
   }
 
+  // Get the complete path of the osquery process binary.
+  auto exec_path = fs::system_complete(fs::path(qd[0]["path"]));
+  if (!safePermissions(
+          exec_path.parent_path().string(), exec_path.string(), true)) {
+    // osqueryd binary has become unsafe.
+    LOG(ERROR) << "osqueryd has unsafe permissions: " << exec_path.string();
+    ::exit(EXIT_FAILURE);
+  }
+
   auto worker_pid = fork();
   if (worker_pid < 0) {
     // Unrecoverable error, cannot create a worker process.
@@ -335,8 +344,6 @@ void WatcherRunner::createWorker() {
   } else if (worker_pid == 0) {
     // This is the new worker process, no watching needed.
     setenv("OSQUERY_WORKER", std::to_string(getpid()).c_str(), 1);
-    // Get the complete path of the osquery process binary.
-    auto exec_path = fs::system_complete(fs::path(qd[0]["path"]));
     execve(exec_path.string().c_str(), argv_, environ);
     // Code should never reach this point.
     LOG(ERROR) << "osqueryd could not start worker process";
@@ -401,13 +408,13 @@ bool WatcherRunner::createExtension(cons
   return true;
 }
 
-void WatcherWatcherRunner::enter() {
+void WatcherWatcherRunner::start() {
   while (true) {
     if (getppid() != watcher_) {
       // Watcher died, the worker must follow.
       VLOG(1) << "osqueryd worker (" << getpid()
               << ") detected killed watcher (" << watcher_ << ")";
-      Dispatcher::removeServices();
+      Dispatcher::stopServices();
       Dispatcher::joinServices();
       ::exit(EXIT_SUCCESS);
     }
