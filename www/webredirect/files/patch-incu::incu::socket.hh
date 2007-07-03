--- ./incu/incu/socket.hh.orig	2003-01-16 01:35:07.000000000 +0800
+++ ./incu/incu/socket.hh	2007-07-03 16:55:53.369394880 +0800
@@ -73,7 +73,8 @@
     std::streambuf* inbuf;
     std::streambuf* outbuf;
   };
-  
+
+  std::ostream& operator << (std::ostream&, const SockaddrIn&);
 }
 
 #endif // INCU_SOCKET
