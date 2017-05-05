--- src/3rdparty/chromium/third_party/webrtc/base/taskrunner.cc.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/third_party/webrtc/base/taskrunner.cc
@@ -102,7 +102,7 @@ void TaskRunner::InternalRunTasks(bool i
   std::vector<Task *>::iterator it;
   it = std::remove(tasks_.begin(),
                    tasks_.end(),
-                   reinterpret_cast<Task *>(NULL));
+                   static_cast<Task *>(NULL));
 
   tasks_.erase(it, tasks_.end());
 
