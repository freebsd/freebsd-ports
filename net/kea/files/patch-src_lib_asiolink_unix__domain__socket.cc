--- src/lib/asiolink/unix_domain_socket.cc.orig	2024-07-25 08:50:58 UTC
+++ src/lib/asiolink/unix_domain_socket.cc
@@ -83,7 +83,7 @@ class UnixDomainSocketImpl : public boost::enable_shar
     /// @param buffer Buffers holding the data to be sent.
     /// @param handler User supplied callback to be invoked when data have
     /// been sent or sending error is signalled.
-    void doSend(const boost::asio::const_buffers_1& buffer,
+    void doSend(const boost::asio::const_buffer& buffer,
                 const UnixDomainSocket::Handler& handler);
 
 
@@ -103,7 +103,7 @@ class UnixDomainSocketImpl : public boost::enable_shar
     /// @param ec Error code returned as a result of sending the data.
     /// @param length Length of the data sent.
     void sendHandler(const UnixDomainSocket::Handler& remote_handler,
-                     const boost::asio::const_buffers_1& buffer,
+                     const boost::asio::const_buffer& buffer,
                      const boost::system::error_code& ec,
                      size_t length);
 
@@ -127,7 +127,7 @@ class UnixDomainSocketImpl : public boost::enable_shar
     /// @param buffer A buffer into which the data should be received.
     /// @param handler User supplied callback invoked when data have been
     /// received on an error is signalled.
-    void doReceive(const boost::asio::mutable_buffers_1& buffer,
+    void doReceive(const boost::asio::mutable_buffer& buffer,
                    const UnixDomainSocket::Handler& handler);
 
     /// @brief Local handler invoked as a result of asynchronous receive.
@@ -146,7 +146,7 @@ class UnixDomainSocketImpl : public boost::enable_shar
     /// @param ec Error code returned as a result of asynchronous receive.
     /// @param length Size of the received data.
     void receiveHandler(const UnixDomainSocket::Handler& remote_handler,
-                        const boost::asio::mutable_buffers_1& buffer,
+                        const boost::asio::mutable_buffer& buffer,
                         const boost::system::error_code& ec,
                         size_t length);
 
@@ -197,7 +197,7 @@ void
 }
 
 void
-UnixDomainSocketImpl::doSend(const boost::asio::const_buffers_1& buffer,
+UnixDomainSocketImpl::doSend(const boost::asio::const_buffer& buffer,
                              const UnixDomainSocket::Handler& handler) {
     auto local_handler = std::bind(&UnixDomainSocketImpl::sendHandler,
                                    shared_from_this(),
@@ -207,7 +207,7 @@ UnixDomainSocketImpl::sendHandler(const UnixDomainSock
 
 void
 UnixDomainSocketImpl::sendHandler(const UnixDomainSocket::Handler& remote_handler,
-                                  const boost::asio::const_buffers_1& buffer,
+                                  const boost::asio::const_buffer& buffer,
                                   const boost::system::error_code& ec,
                                   size_t length) {
     // The asynchronous send may return EWOULDBLOCK or EAGAIN on some
@@ -230,7 +230,7 @@ void
 }
 
 void
-UnixDomainSocketImpl::doReceive(const boost::asio::mutable_buffers_1& buffer,
+UnixDomainSocketImpl::doReceive(const boost::asio::mutable_buffer& buffer,
                                 const UnixDomainSocket::Handler& handler) {
     auto local_handler = std::bind(&UnixDomainSocketImpl::receiveHandler,
                                    shared_from_this(),
@@ -240,7 +240,7 @@ UnixDomainSocketImpl::receiveHandler(const UnixDomainS
 
 void
 UnixDomainSocketImpl::receiveHandler(const UnixDomainSocket::Handler& remote_handler,
-                                     const boost::asio::mutable_buffers_1& buffer,
+                                     const boost::asio::mutable_buffer& buffer,
                                      const boost::system::error_code& ec,
                                      size_t length) {
     // The asynchronous receive may return EWOULDBLOCK or EAGAIN on some
