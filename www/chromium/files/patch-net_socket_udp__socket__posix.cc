--- net/socket/udp_socket_posix.cc.orig	2022-03-25 21:59:56 UTC
+++ net/socket/udp_socket_posix.cc
@@ -574,7 +574,7 @@ int UDPSocketPosix::SetDoNotFragment() {
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
