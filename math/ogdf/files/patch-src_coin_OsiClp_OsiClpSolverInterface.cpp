OsiClpSolverInterface.cpp:1451:50: error: reinterpret_cast from 'nullptr_t' to 'int *' is not allowed
    messagesPointer->setDetailMessages(100,10000,reinterpret_cast<int *> (NULL));
                                                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- src/coin/OsiClp/OsiClpSolverInterface.cpp.orig	2015-05-29 15:36:45 UTC
+++ src/coin/OsiClp/OsiClpSolverInterface.cpp
@@ -1422,7 +1422,7 @@ OsiClpSolverInterface::setupForRepeatedUse(int senseOf
   if (stopPrinting) {
     CoinMessages * messagesPointer = modelPtr_->messagesPointer();
     // won't even build messages
-    messagesPointer->setDetailMessages(100,10000,reinterpret_cast<int *> (NULL));
+    messagesPointer->setDetailMessages(100,10000,static_cast<int *> (NULL));
   }
 #endif
 }
