--- net/socket/unix_domain_client_socket_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ net/socket/unix_domain_client_socket_posix.cc
@@ -60,7 +60,7 @@ bool UnixDomainClientSocket::FillAddress(const std::st
     return true;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, so we are adding it. |addr_len| must specify the
   // length of the structure exactly, as potentially the socket name may
