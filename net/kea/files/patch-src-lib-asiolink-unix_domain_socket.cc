--- src/lib/asiolink/unix_domain_socket.cc.orig	2017-10-05 13:00:03 UTC
+++ src/lib/asiolink/unix_domain_socket.cc
@@ -287,7 +287,11 @@ UnixDomainSocket::UnixDomainSocket(IOSer
 
 int
 UnixDomainSocket::getNative() const {
+#if BOOST_VERSION < 106600
     return (impl_->socket_.native());
+#else
+    return (impl_->socket_.native_handle());
+#endif
 }
 
 int
