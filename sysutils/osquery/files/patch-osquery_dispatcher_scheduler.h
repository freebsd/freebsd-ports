--- osquery/dispatcher/scheduler.h.orig	2015-05-05 00:16:41 UTC
+++ osquery/dispatcher/scheduler.h
@@ -23,7 +23,7 @@ class SchedulerRunner : public InternalR
 
  public:
   /// The Dispatcher thread entry point.
-  void enter();
+  void start();
 
  protected:
   /// The UNIX domain socket path for the ExtensionManager.
