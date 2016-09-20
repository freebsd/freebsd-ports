Fix the build on FreeBSD 9, which does not have LLINDEX.
--- src/network/socket/qnativesocketengine_unix.cpp.orig	2016-04-13 21:57:35 UTC
+++ src/network/socket/qnativesocketengine_unix.cpp
@@ -904,8 +904,11 @@ qint64 QNativeSocketEnginePrivate::nativ
             if (cmsgptr->cmsg_level == IPPROTO_IP && cmsgptr->cmsg_type == IP_RECVIF
                     && cmsgptr->cmsg_len >= CMSG_LEN(sizeof(sockaddr_dl))) {
                 sockaddr_dl *sdl = reinterpret_cast<sockaddr_dl *>(CMSG_DATA(cmsgptr));
-
+#    if !defined(LLINDEX)
+                header->ifindex = sdl->sdl_index;
+#    else
                 header->ifindex = LLINDEX(sdl);
+#    endif
             }
 #  endif
 #endif
