--- ./base/posix/unix_domain_socket_linux.cc.orig	2014-08-12 21:01:28.000000000 +0200
+++ ./base/posix/unix_domain_socket_linux.cc	2014-08-13 09:56:56.000000000 +0200
@@ -18,6 +18,15 @@
 #include "base/posix/eintr_wrapper.h"
 #include "base/stl_util.h"
 
+#if defined(__FreeBSD__)
+// Port over Linux ucred structure
+struct ucred {
+  pid_t pid; // process ID of the sending process
+  uid_t uid; // user ID of the sending process
+  gid_t gid; // group ID of the sending process
+};
+#endif
+
 const size_t UnixDomainSocket::kMaxFileDescriptors = 16;
 
 // Creates a connected pair of UNIX-domain SOCK_SEQPACKET sockets, and passes
@@ -35,7 +44,13 @@
 // static
 bool UnixDomainSocket::EnableReceiveProcessId(int fd) {
   const int enable = 1;
+#if defined(__FreeBSD__)
+  // XXX(rene) do this? :
+  // taken from dbus, Academic Free License 2.1 / GPL 2+
+  return 0; // fake OK
+#else
   return setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &enable, sizeof(enable)) == 0;
+#endif
 }
 
 // static
@@ -131,7 +146,11 @@
         wire_fds_len = payload_len / sizeof(int);
       }
       if (cmsg->cmsg_level == SOL_SOCKET &&
+#if defined(__FreeBSD__)
+        1) { // XXX(rene) carpet getting full ...
+#else
           cmsg->cmsg_type == SCM_CREDENTIALS) {
+#endif
         DCHECK(payload_len == sizeof(struct ucred));
         DCHECK(pid == -1);
         pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
