--- src/session.cpp.orig	2007-01-13 19:28:47.000000000 +0200
+++ src/session.cpp	2008-07-03 16:33:51.000000000 +0300
@@ -130,7 +130,7 @@
 
 Session* Session::detatch(Client* a_Client)
 {
-    list<Client*>::iterator clientIter = NULL;
+    list<Client*>::iterator clientIter = m_ClientList.end();
 
     assert(a_Client);
     clientIter = find(m_ClientList.begin(), m_ClientList.end(), a_Client);
