--- src/gdl2gdl.cpp.orig	2024-11-02 17:32:21 UTC
+++ src/gdl2gdl.cpp
@@ -29,6 +29,7 @@
 #include <sys/mman.h>   /* shared memory and mmap() */
 #include <sys/shm.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include "dinterpreter.hpp"
 
 static bool atexit_already_done = false;
@@ -103,13 +104,29 @@ void g2gAsynchronousReturnTrap() {
 }
 
 void g2gAsynchronousReturnTrap() {
-  while (g2gMap.size() > 0) {
-    for (g2gMapIter it = g2gMap.begin(); it != g2gMap.end(); ++it) {
-	  if ( (*it).second.status==1 && (*it).second.nowait ) gdl_ipc_read_client_nowait((*it).first);
-	}
-	usleep (10000);
+  while (!g2gMap.empty()) {
+    for (auto g2gMapIter = g2gMap.cbegin(); g2gMapIter != g2gMap.cend();) {
+      if ((*g2gMapIter).second.status == 1 && (*g2gMapIter).second.nowait) {
+        gdl_ipc_read_client_nowait((*g2gMapIter).first);
+      }
+      // contrib by @jkohnert - to be used should a concurrency problem with the spawn command appear.
+      // At the moment better to keep initial version (GD).
+      // // we need to take care of our children, use a no-hang wait call to check the pid
+      // int status = -1;
+      // if (waitpid((*g2gMapIter).first, &status, WUNTRACED | WCONTINUED | WNOHANG) == -1) {
+      //   // we're out of luck, wait returns an error, so break the loop and exit
+      //   std::cerr << "g2gAsynchronousReturnTrap exiting" << std::endl;
+      //   break;
+      // }
+      // // remove stopped children from the map
+      // if (WIFEXITED(status) || WIFSIGNALED(status))
+      //   g2gMap.erase(g2gMapIter++);
+      //   // we need to manually count here, since we're modifying the map in the loop
+      // else
+       ++g2gMapIter;
+    }
+    usleep(10000); // GD: should replace usleep by nanosleep everywhere !
   }
-//  std::cerr<<"g2gAsynchronousReturnTrap exiting"<<std::endl;
 }
 
 int gdl_ipc_write_to_client(EnvT* e, DLong* id, const std::string & command, bool nowait = true) {
@@ -419,7 +436,7 @@ messageBoxHandle StartIndividualClientMessageChannel(s
      
   name=G2G_SERVER_QUEUE_BASENAME+i2s(getpid())+"_"+i2s(++ClientSessionNumber);
   messageBoxHandle h;
-  if ((h = mq_open(name.c_str(), O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
+  if ((h = mq_open(name.c_str(), O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == (messageBoxHandle)-1) {
    throw GDLException("Server: mq_open (client) :"+string(strerror(errno)));
   }
   return h;
@@ -430,7 +447,7 @@ void gdl_ipc_ClientGetsMailboxAddress(std::string & s)
 }
 void gdl_ipc_ClientGetsMailboxAddress(std::string & s) {
   g2gClientMailbox=s;
-  if ((gdl2gdlMessageBoxHandle = mq_open(g2gClientMailbox.c_str(), O_WRONLY)) == -1) {
+  if ((gdl2gdlMessageBoxHandle = mq_open(g2gClientMailbox.c_str(), O_WRONLY)) == (messageBoxHandle)-1) {
    throw GDLException("Server: mq_open (server) :"+string(strerror(errno)));
   }
   //here is a good point to start to be absolutely silent
@@ -1006,7 +1023,7 @@ namespace lib {
 	  params.description.clear();
 	  params.status=0;
 	  params.obj=o;
-	  bool startspy = (g2gMap.size() == 0) ; //will start a spy detached thread for NOWAIT operations, that will end itself when g2GMap is empty
+	  bool startspy = (g2gMap.empty()) ; //will start a spy detached thread for NOWAIT operations, that will end itself when g2GMap is empty
 	  g2gMap.insert(std::pair<pid_t,gdl2gdlparams>(subprocess_pid,params));
 	  g2gMap.at(subprocess_pid).MessageChannelHandle=id;
 	  // insure communication with child is OK waiting for a status change
