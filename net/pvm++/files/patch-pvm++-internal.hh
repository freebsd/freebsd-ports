--- pvm++/internal.hh.orig	2013-11-16 19:59:44.000000000 +0100
+++ pvm++/internal.hh	2013-11-16 20:03:28.000000000 +0100
@@ -37,7 +37,7 @@
 			long int EndSec, long int EnduSec);
   };
 
-  namespace Internal
+  namespace Internal_
   {
 
     void GetTasks (int What, TaskSet & Result);
@@ -69,7 +69,7 @@
     extern HandlerTableType *HandlerTable;
     extern QueueType *ReceivedQueue;
 
-  } // namespace Internal
+  } // namespace Internal_
 
 } // namespace Pvm
 
