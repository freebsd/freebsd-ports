Obtained from:	https://github.com/nghttp2/nghttp2/commit/cbba1ebf8fcecb24392f0cc07b1235b17d0de9d8

--- src/asio_server_connection.h.orig	2019-04-18 06:08:36 UTC
+++ src/asio_server_connection.h
@@ -51,6 +51,12 @@
 #include "util.h"
 #include "template.h"
 
+#if BOOST_VERSION >= 107000
+#define GET_IO_SERVICE(s) ((boost::asio::io_context&)(s).get_executor().context())
+#else
+#define GET_IO_SERVICE(s) ((s).get_io_service())
+#endif
+
 namespace nghttp2 {
 
 namespace asio_http2 {
@@ -71,7 +77,7 @@ public:
       SocketArgs &&... args)
       : socket_(std::forward<SocketArgs>(args)...),
         mux_(mux),
-        deadline_(socket_.get_io_service()),
+        deadline_(GET_IO_SERVICE(socket_)),
         tls_handshake_timeout_(tls_handshake_timeout),
         read_timeout_(read_timeout),
         writing_(false),
@@ -82,7 +88,7 @@ public:
     boost::system::error_code ec;
 
     handler_ = std::make_shared<http2_handler>(
-        socket_.get_io_service(), socket_.lowest_layer().remote_endpoint(ec),
+        GET_IO_SERVICE(socket_), socket_.lowest_layer().remote_endpoint(ec),
         [this]() { do_write(); }, mux_);
     if (handler_->start() != 0) {
       stop();
