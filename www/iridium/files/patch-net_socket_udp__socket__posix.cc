--- net/socket/udp_socket_posix.cc.orig	2024-08-01 05:47:53 UTC
+++ net/socket/udp_socket_posix.cc
@@ -521,12 +521,17 @@ int UDPSocketPosix::SetRecvTos() {
     }
   }
 
+#ifdef IP_RECVTOS
   int rv = setsockopt(socket_, IPPROTO_IP, IP_RECVTOS, &ecn, sizeof(ecn));
+#else
+  int rv = -1;
+  errno = EOPNOTSUPP;
+#endif
   return rv == 0 ? OK : MapSystemError(errno);
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
@@ -547,7 +552,7 @@ int UDPSocketPosix::SetBroadcast(bool broadcast) {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
@@ -885,7 +890,7 @@ int UDPSocketPosix::DoBind(const IPEndPoint& address) 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   if (last_error == EINVAL)
     return ERR_ADDRESS_IN_USE;
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   if (last_error == EADDRNOTAVAIL)
     return ERR_ADDRESS_IN_USE;
 #endif
