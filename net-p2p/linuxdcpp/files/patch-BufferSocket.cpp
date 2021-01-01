--- dcpp/BufferedSocket.cpp.orig	2014-06-18 00:29:48.737534795 +0200
+++ dcpp/BufferedSocket.cpp	2011-04-17 19:57:09.000000000 +0200
@@ -478,7 +478,7 @@
 
 void BufferedSocket::addTask(Tasks task, TaskData* data) {
 	dcassert(task == DISCONNECT || task == SHUTDOWN || task == UPDATED || sock.get());
-	tasks.push_back(make_pair(task, data)); taskSem.signal();
+	tasks.push_back(make_pair(task, boost::shared_ptr<TaskData>(data))); taskSem.signal();
 }
 
 } // namespace dcpp
