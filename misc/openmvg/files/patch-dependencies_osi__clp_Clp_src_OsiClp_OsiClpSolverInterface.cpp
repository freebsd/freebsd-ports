--- dependencies/osi_clp/Clp/src/OsiClp/OsiClpSolverInterface.cpp.orig	2018-04-10 05:08:11 UTC
+++ dependencies/osi_clp/Clp/src/OsiClp/OsiClpSolverInterface.cpp
@@ -1449,7 +1449,7 @@ OsiClpSolverInterface::setupForRepeatedU
   if (stopPrinting) {
     CoinMessages * messagesPointer = modelPtr_->messagesPointer();
     // won't even build messages
-    messagesPointer->setDetailMessages(100,10000,reinterpret_cast<int *> (NULL));
+    messagesPointer->setDetailMessages(100,10000,static_cast<int *> (NULL));
   }
 #endif
 }
