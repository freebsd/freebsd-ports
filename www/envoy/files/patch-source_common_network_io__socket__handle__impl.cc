--- source/common/network/io_socket_handle_impl.cc.orig	2023-04-27 12:00:08 UTC
+++ source/common/network/io_socket_handle_impl.cc
@@ -195,7 +195,7 @@ Api::IoCallUint64Result IoSocketHandleImpl::sendmsg(co
     return sysCallResultToIoCallResult(result);
   } else {
     const size_t space_v6 = CMSG_SPACE(sizeof(in6_pktinfo));
-    const size_t space_v4 = CMSG_SPACE(sizeof(in_pktinfo));
+    const size_t space_v4 = CMSG_SPACE(sizeof(in_addr));
 
     // FreeBSD only needs in_addr size, but allocates more to unify code in two platforms.
     const size_t cmsg_space = (self_ip->version() == Address::IpVersion::v4) ? space_v4 : space_v6;
@@ -223,7 +223,7 @@ Api::IoCallUint64Result IoSocketHandleImpl::sendmsg(co
 #else
       cmsg->cmsg_type = IP_SENDSRCADDR;
       cmsg->cmsg_len = CMSG_LEN(sizeof(in_addr));
-      *(reinterpret_cast<struct in_addr*>(CMSG_DATA(cmsg))).s_addr = self_ip->ipv4()->address();
+      reinterpret_cast<struct in_addr*>(CMSG_DATA(cmsg))->s_addr = self_ip->ipv4()->address();
 #endif
     } else if (self_ip->version() == Address::IpVersion::v6) {
       cmsg->cmsg_len = CMSG_LEN(sizeof(in6_pktinfo));
