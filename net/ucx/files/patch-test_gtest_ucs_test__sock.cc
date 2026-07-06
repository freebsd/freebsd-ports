--- test/gtest/ucs/test_sock.cc.orig	2026-02-04 09:52:47 UTC
+++ test/gtest/ucs/test_sock.cc
@@ -102,7 +102,6 @@ UCS_TEST_F(test_socket, sockaddr_sizeof) {
     struct sockaddr *saddr     = (struct sockaddr*)&ss;
     size_t size;
 
-
     /* Check with IPv4 */
     {
         size             = 0;
@@ -551,6 +550,10 @@ UCS_TEST_F(test_socket, socket_setopt) {
         level   = SOL_SOCKET;
         optname = SO_REUSEADDR;
         optval  = 1;
+
+#if defined(__FreeBSD__)
+        UCS_TEST_SKIP_R("IPPROTO_TCP/SO_REUSEADDR returns success on FreeBSD");
+#endif
 
         status = ucs_socket_setopt(fd, level, optname, &optval, optlen);
         EXPECT_UCS_OK(status);
