--- osquery/dispatcher/scheduler.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/dispatcher/scheduler.cpp
@@ -150,7 +150,7 @@ void launchQuery(const std::string& name
   }
 }
 
-void SchedulerRunner::enter() {
+void SchedulerRunner::start() {
   time_t t = std::time(nullptr);
   struct tm* local = std::localtime(&t);
   unsigned long int i = local->tm_sec;
