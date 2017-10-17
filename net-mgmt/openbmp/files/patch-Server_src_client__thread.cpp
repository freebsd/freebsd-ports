--- Server/src/client_thread.cpp.orig	2017-09-14 09:34:45 UTC
+++ Server/src/client_thread.cpp
@@ -227,7 +227,7 @@ void *ClientThread(void *arg) {
         close(sock_fds[0]);
         close(sock_fds[1]);
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) and !defined(__FreeBSD__)
     } catch (abi::__forced_unwind&) {
         close(sock_fds[0]);
         close(sock_fds[1]);
