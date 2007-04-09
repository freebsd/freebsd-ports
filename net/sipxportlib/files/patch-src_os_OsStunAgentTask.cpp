--- src/os/OsStunAgentTask.cpp.orig	Sat Apr  7 19:49:56 2007
+++ src/os/OsStunAgentTask.cpp	Sat Apr  7 19:57:37 2007
@@ -9,6 +9,7 @@
 
 // SYSTEM INCLUDES
 #include <assert.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "os/OsStunAgentTask.h"
@@ -374,12 +375,12 @@
                     pQueuedEvent = (OsQueuedEvent*) pTimer->getNotifier() ;
                     if (pQueuedEvent)
                     {
-                        pQueuedEvent->setUserData((int) pSocket) ;
+                        pQueuedEvent->setUserData((int) ((uintptr_t)pSocket)) ;
                     }
                 }
                 else
                 {
-                    pTimer = new OsTimer(getMessageQueue(), (int) pSocket) ;
+                    pTimer = new OsTimer(getMessageQueue(), (int) ((uintptr_t)pSocket)) ;
                     pQueuedEvent = (OsQueuedEvent*)pTimer->getNotifier();
                 }
 
