Obtained from:	https://github.com/nghttp2/nghttp2/commit/318e0c8447e2399e7c1e95d8ae8d00118ccea5f7

--- src/util.cc.orig	2021-09-21 13:08:54 UTC
+++ src/util.cc
@@ -1688,6 +1688,7 @@ int daemonize(int nochdir, int noclose) {
 #endif // !defined(__APPLE__)
 }
 
+#ifdef ENABLE_HTTP3
 int msghdr_get_local_addr(Address &dest, msghdr *msg, int family) {
   switch (family) {
   case AF_INET:
@@ -1721,6 +1722,7 @@ int msghdr_get_local_addr(Address &dest, msghdr *msg, 
 
   return -1;
 }
+#endif // ENABLE_HTTP3
 
 } // namespace util
 
