--- Server/src/client_thread.cpp.orig	2017-09-14 09:34:45 UTC
+++ Server/src/client_thread.cpp
@@ -242,7 +242,7 @@ void *ClientThread(void *arg) {
         LOG_INFO("%s: %s - Thread for sock [%d] ended", cInfo.client->c_ip, str, cInfo.client->c_sock);
         close(sock_fds[0]);
         close(sock_fds[1]);
-#ifndef __APPLE__
+#if !defined(__APPLE__) and !defined(__FreeBSD__)
     } catch (abi::__forced_unwind&) {
         close(sock_fds[0]);
         close(sock_fds[1]);
