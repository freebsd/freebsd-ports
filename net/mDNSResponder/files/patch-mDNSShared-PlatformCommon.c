--- mDNSShared/PlatformCommon.c.orig	2019-06-27 09:29:40 UTC
+++ mDNSShared/PlatformCommon.c
@@ -335,7 +335,9 @@ mDNSexport mDNSBool mDNSPosixTCPSocketSetup(int *fd, m
     int sa_family = (addrType == mDNSAddrType_IPv4) ? AF_INET : AF_INET6;
     int err;
     int sock;
+#if !defined(TARGET_OS_FREEBSD)
     mDNSu32 lowWater = 15384;
+#endif
 
     sock = socket(sa_family, SOCK_STREAM, IPPROTO_TCP);
     if (sock < 3)
@@ -398,12 +400,14 @@ mDNSexport mDNSBool mDNSPosixTCPSocketSetup(int *fd, m
     if (port)
         port->NotAnInteger = outTcpPort->NotAnInteger;
 
+#if !defined(TARGET_OS_FREEBSD)
     err = setsockopt(sock, IPPROTO_TCP, TCP_NOTSENT_LOWAT, &lowWater, sizeof lowWater);
     if (err < 0)
     {
         LogMsg("mDNSPosixTCPSocketSetup: TCP_NOTSENT_LOWAT failed: %s", strerror(errno));
         return mDNSfalse;
     }
+#endif
 
     return mDNStrue;
 }
@@ -426,7 +430,9 @@ mDNSexport TCPSocket *mDNSPosixDoTCPListenCallback(int
     int failed;
     char *nbp;
     int i;
+#if !defined(TARGET_OS_FREEBSD)
     mDNSu32 lowWater = 16384;
+#endif
     // When we remember our connection, we remember a name that we can print for logging.   But
     // since we are the listener in this case, we don't /have/ a name for it.   This buffer
     // is used to print the IP address into a human readable string which will serve that purpose
@@ -448,6 +454,7 @@ mDNSexport TCPSocket *mDNSPosixDoTCPListenCallback(int
         goto out;
     }
 
+#if !defined(TARGET_OS_FREEBSD)
     failed = setsockopt(remoteSock, IPPROTO_TCP, TCP_NOTSENT_LOWAT,
                         &lowWater, sizeof lowWater);
     if (failed < 0)
@@ -456,6 +463,7 @@ mDNSexport TCPSocket *mDNSPosixDoTCPListenCallback(int
         LogMsg("mDNSPosixDoTCPListenCallback: TCP_NOTSENT_LOWAT returned %d", errno);
         goto out;
     }
+#endif
     
     if (address.sa.sa_family == AF_INET6)
     {
