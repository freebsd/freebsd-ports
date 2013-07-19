--- third_party/libjingle/source/talk/base/taskrunner.cc	2013-07-03 23:54:05.000000000 -0400
+++ third_party/libjingle/source/talk/base/taskrunner.cc	2013-07-19 00:46:25.000000000 -0400
@@ -119,7 +119,7 @@
   std::vector<Task *>::iterator it;
   it = std::remove(tasks_.begin(),
                    tasks_.end(),
-                   reinterpret_cast<Task *>(NULL));
+                   static_cast<Task *>(0));
 
   tasks_.erase(it, tasks_.end());
 
