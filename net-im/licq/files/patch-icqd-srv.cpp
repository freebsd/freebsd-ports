--- src/icqd-srv.cpp.orig	Wed Jun 25 08:40:16 2003
+++ src/icqd-srv.cpp	Fri May  7 13:07:09 2004
@@ -2145,7 +2145,7 @@ void CICQDaemon::ProcessMessageFam(CBuff
       char *szMsg = gTranslator.RNToN(message);
       delete [] message;
 
-      gTranslator.ServerToClient(szMsg);
+//      gTranslator.ServerToClient(szMsg);
 
       bool bNewUser = false;
       ICQUser *u = gUserManager.FetchUser(nUin, LOCK_W);
