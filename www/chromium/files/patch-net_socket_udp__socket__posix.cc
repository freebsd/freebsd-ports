--- net/socket/udp_socket_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ net/socket/udp_socket_posix.cc
@@ -636,7 +636,7 @@ int UDPSocketPosix::SetDoNotFragment() {
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
