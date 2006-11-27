--- player/app/plugin/hxbackend.cpp.orig	Sun Oct 22 13:50:24 2006
+++ player/app/plugin/hxbackend.cpp	Sun Oct 22 13:50:24 2006
@@ -358,5 +357,5 @@ nsresult CHXPlayerBackend::ReceiveMessag
     {
         /* Trim back the buffer to the size we actually used (plus NULL) */
-        pBuf = (char*)realloc(pBuf, nPos + 1);
+        *ppBuf = (char*)realloc(pBuf, nPos + 1);
     }
     else
@@ -509,5 +500,5 @@
         fcntl(cbsockets[1], F_SETFD, 0);
 
-        m_nChildPid = fork();
+        m_nChildPid = vfork();
         if(m_nChildPid < 0)
         {
