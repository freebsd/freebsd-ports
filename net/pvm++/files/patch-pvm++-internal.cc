--- pvm++/internal.cc.orig	2013-11-16 19:59:44.000000000 +0100
+++ pvm++/internal.cc	2013-11-16 20:02:56.000000000 +0100
@@ -27,7 +27,7 @@
 namespace Pvm
 {
 
-  namespace Internal
+  namespace Internal_
   {
   
     void
@@ -225,9 +225,9 @@
     HandlerTableType *HandlerTable;
     QueueType *ReceivedQueue;
   
-  } // namespace Internal
+  } // namespace Internal_
   
-  using namespace Internal;
+  using namespace Internal_;
 
   void
   AccessPrivate::UnPack (const QueueIterator &QueuePos, StructSet &What,
