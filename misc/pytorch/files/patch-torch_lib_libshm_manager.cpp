-- Replace C++20 std::erase_if with C++17 erase-remove idiom for compatibility
-- with the C++17 standard used when building this port.
--- torch/lib/libshm/manager.cpp.orig	2026-05-16 06:23:44 UTC
+++ torch/lib/libshm/manager.cpp
@@ -46,7 +46,7 @@ static void unregister_fd(int fd) {
 }
 
 static void unregister_fd(int fd) {
-  std::erase_if(pollfds, [fd](const struct pollfd& pfd) { return pfd.fd == fd; });
+  pollfds.erase(std::remove_if(pollfds.begin(), pollfds.end(), [fd](const struct pollfd& pfd) { return pfd.fd == fd; }), pollfds.end());
   client_sessions.erase(fd);
 }
 
