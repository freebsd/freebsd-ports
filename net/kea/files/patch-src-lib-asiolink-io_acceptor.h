--- src/lib/asiolink/io_acceptor.h.orig	2017-10-05 13:00:03 UTC
+++ src/lib/asiolink/io_acceptor.h
@@ -47,7 +47,11 @@ public:
 
     /// @brief Returns file descriptor of the underlying socket.
     virtual int getNative() const {
+#if BOOST_VERSION < 106600
         return (acceptor_->native());
+#else
+        return (acceptor_->native_handle());
+#endif
     }
 
     /// @brief Opens acceptor socket given the endpoint.
