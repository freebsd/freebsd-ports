--- Core/MultiThreading/ThreadedCommandProcessor.cpp.orig	2015-02-12 13:47:38 UTC
+++ Core/MultiThreading/ThreadedCommandProcessor.cpp
@@ -175,7 +175,7 @@ namespace Orthanc
   {
     boost::mutex::scoped_lock lock(mutex_);
 
-    while (!remainingCommands_ == 0)
+    while (remainingCommands_ != 0)
     {
       processedCommand_.wait(lock);
     }
