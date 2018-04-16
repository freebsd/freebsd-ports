--- Clp/src/OsiClp/OsiClpSolverInterface.cpp.orig	2018-04-16 06:57:00 UTC
+++ Clp/src/OsiClp/OsiClpSolverInterface.cpp
@@ -1448,7 +1448,7 @@ OsiClpSolverInterface::setupForRepeatedU
   if (stopPrinting) {
     CoinMessages * messagesPointer = modelPtr_->messagesPointer();
     // won't even build messages 
-    messagesPointer->setDetailMessages(100,10000,reinterpret_cast<int *> (NULL));
+    messagesPointer->setDetailMessages(100,10000,nullptr);
   }
 #endif
 }
