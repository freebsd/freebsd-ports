--- net/socket/unix_domain_client_socket_posix.cc.orig	2021-12-14 11:45:09 UTC
+++ net/socket/unix_domain_client_socket_posix.cc
@@ -60,7 +60,7 @@ bool UnixDomainClientSocket::FillAddress(const std::st
     return true;
   }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, so we are adding it. |addr_len| must specify the
   // length of the structure exactly, as potentially the socket name may
