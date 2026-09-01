--- net/socket/udp_socket_posix.h.orig	2026-08-31 10:59:09 UTC
+++ net/socket/udp_socket_posix.h
@@ -451,7 +451,7 @@ class NET_EXPORT UDPSocketPosix {
       size_t maximum_packet_size);
 
   // recvmmsg() and GRO are only available on Linux, ChromeOS, and Android.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   base::expected<DatagramsMetadata, Error> InternalReadMultipleWithGro(
       IOBuffer* buffer,
       size_t buf_len,
