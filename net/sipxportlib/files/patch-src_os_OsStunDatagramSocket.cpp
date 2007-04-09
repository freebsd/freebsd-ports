--- src/os/OsStunDatagramSocket.cpp.orig	Sat Apr  7 20:05:25 2007
+++ src/os/OsStunDatagramSocket.cpp	Sat Apr  7 20:06:07 2007
@@ -13,6 +13,7 @@
 #ifndef _WIN32
 #include <netinet/in.h>
 #endif
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "os/OsStunDatagramSocket.h"
@@ -61,7 +62,7 @@
     mpNotification = pNotification ;
     mStunOptions = iStunOptions ;
 
-    mpTimer = new OsTimer(pStunAgent->getMessageQueue(), (int) this) ;
+    mpTimer = new OsTimer(pStunAgent->getMessageQueue(), (int) ((uintptr_t)this)) ;
 
     // If enabled, kick off first stun request
     if (mbEnabled)
@@ -602,7 +603,7 @@
         pContact->eContactType = NAT_MAPPED;
         pContact->iPort = mStunPort;
         
-        mpNotification->signal((int)pContact) ;
+        mpNotification->signal((int)((uintptr_t)pContact)) ;
         mpNotification = NULL ;
     }
 }
