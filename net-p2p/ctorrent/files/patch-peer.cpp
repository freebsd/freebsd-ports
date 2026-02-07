--- peer.cpp.orig	2008-06-15 00:00:19 UTC
+++ peer.cpp
@@ -66,7 +66,8 @@ int btBasic::IpEquiv(struct sockaddr_in addr)
 //  CONSOLE.Debug_n("IpEquiv: %s <=> ", inet_ntoa(m_sin.sin_addr));
 //  CONSOLE.Debug_n("%s", inet_ntoa(addr.sin_addr));
 //  CONSOLE.Debug_n("");
-  return (memcmp(&m_sin.sin_addr,&addr.sin_addr,sizeof(struct in_addr)) == 0) ? 
+  return ((memcmp(&m_sin.sin_addr,&addr.sin_addr,sizeof(struct in_addr)) == 0)
+    && m_sin.sin_port == addr.sin_port) ?
     1 : 0;
 }
 
