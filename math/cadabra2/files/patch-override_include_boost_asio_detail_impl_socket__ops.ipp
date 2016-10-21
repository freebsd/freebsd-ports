--- override/include/boost/asio/detail/impl/socket_ops.ipp.orig	2016-10-09 22:39:18 UTC
+++ override/include/boost/asio/detail/impl/socket_ops.ipp
@@ -469,7 +469,15 @@ template <typename SockLenType>
 inline int call_connect(SockLenType msghdr::*,
     socket_type s, const socket_addr_type* addr, std::size_t addrlen)
 {
-  return ::connect(s, addr, (SockLenType)addrlen);
+  int res = ::connect(s, addr, (SockLenType)addrlen);
+  if (res == -1 && errno==EINPROGRESS) {
+    fd_set write_fd;
+    FD_ZERO(&write_fd);
+    FD_SET(s, &write_fd);
+    res = ::select (s+1, NULL, &write_fd,NULL,NULL);
+    res = res > 0 ? 0 : res;
+  }
+  return res;
 }
 
 int connect(socket_type s, const socket_addr_type* addr,
