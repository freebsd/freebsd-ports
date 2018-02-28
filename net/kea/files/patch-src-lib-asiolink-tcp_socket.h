--- src/lib/asiolink/tcp_socket.h.orig	2017-10-05 13:00:03 UTC
+++ src/lib/asiolink/tcp_socket.h
@@ -75,7 +75,11 @@ public:
 
     /// \brief Return file descriptor of underlying socket
     virtual int getNative() const {
+#if BOOST_VERSION < 106600
         return (socket_.native());
+#else
+        return (socket_.native_handle());
+#endif
     }
 
     /// \brief Return protocol of socket
