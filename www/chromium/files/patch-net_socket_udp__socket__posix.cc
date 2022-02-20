--- net/socket/udp_socket_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ net/socket/udp_socket_posix.cc
@@ -636,7 +636,7 @@ int UDPSocketPosix::SetDoNotFragment() {
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
