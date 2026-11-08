--- net/socket/udp_socket_posix.h.orig	2026-08-13 16:48:13 UTC
+++ net/socket/udp_socket_posix.h
@@ -409,7 +409,7 @@ class NET_EXPORT UDPSocketPosix {
       size_t buf_len,
       size_t maximum_packet_size);
   // recvmmsg() is only available on Linux, ChromeOS, and Android.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   base::expected<DatagramsMetadata, Error> InternalRecvMmsg(
       IOBuffer* buffer,
       size_t num_messages,
