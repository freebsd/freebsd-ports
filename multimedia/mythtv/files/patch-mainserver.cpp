--- programs/mythbackend/mainserver.cpp.orig	Wed Jan 31 22:16:22 2007
+++ programs/mythbackend/mainserver.cpp	Wed Jan 31 16:16:00 2007
@@ -238,9 +238,9 @@
         return;
     }
 
-    readReadyLock.lock();
+    // readReadyLock.lock();
 
-    sock->Lock();
+    // sock->Lock();
 
     //if (socket->IsInProcess())
     //{
@@ -287,7 +287,7 @@
 
     prt->setup(sock);
 
-    readReadyLock.unlock();
+    //readReadyLock.unlock();
 }
 
 void MainServer::ProcessRequest(MythSocket *sock)
@@ -301,7 +301,7 @@
         ProcessRequestWork(sock);
     }
 
-    sock->Unlock();
+    //sock->Unlock();
     //sock->SetInProcess(false);
 }
 
