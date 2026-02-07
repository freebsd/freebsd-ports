--- Tracker/connection.cpp.orig	2025-12-12 11:29:04 UTC
+++ Tracker/connection.cpp
@@ -248,10 +248,10 @@ void connection_t::read(std::string_view v)
     if (WSAGetLastError() != WSAECONNRESET)
       std::cerr << "send failed: " << Csocket::error2a(WSAGetLastError()) << std::endl;
   }
-  else if (r != ssize(h) + ssize(s))
+  else if (static_cast<size_t>(r) != h.size() + s.size())
   {
 #ifndef WIN32
-    if (r < ssize(h))
+    if (static_cast<size_t>(r) < h.size())
     {
       write_b_ = shared_data(h.size() + s.size());
       memcpy(write_b_.data(), h);
