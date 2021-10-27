Obtained from:	https://github.com/nghttp2/nghttp2/commit/318e0c8447e2399e7c1e95d8ae8d00118ccea5f7

--- src/util.h.orig	2021-09-21 13:08:54 UTC
+++ src/util.h
@@ -916,7 +916,9 @@ std::mt19937 make_mt19937();
 // daemon() using fork().
 int daemonize(int nochdir, int noclose);
 
+#ifdef ENABLE_HTTP3
 int msghdr_get_local_addr(Address &dest, msghdr *msg, int family);
+#endif // ENABLE_HTTP3
 
 } // namespace util
 
