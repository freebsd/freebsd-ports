--- ./programs/mythbackend/mainserver.cpp.orig	2008-03-02 23:47:04.000000000 -0500
+++ ./programs/mythbackend/mainserver.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -251,7 +251,7 @@
         return;
     }
 
-    readReadyLock.lock();
+    // readReadyLock.lock();
 
     ProcessRequestThread *prt = NULL;
     threadPoolLock.lock();
@@ -278,19 +278,19 @@
 
     prt->setup(sock);
 
-    readReadyLock.unlock();
+    // readReadyLock.unlock();
 }
 
 void MainServer::ProcessRequest(MythSocket *sock)
 {
-    sock->Lock();
+    // sock->Lock();
 
     if (sock->bytesAvailable() > 0)
     {
         ProcessRequestWork(sock);
     }
 
-    sock->Unlock();
+    // sock->Unlock();
 }
 
 void MainServer::ProcessRequestWork(MythSocket *sock)
