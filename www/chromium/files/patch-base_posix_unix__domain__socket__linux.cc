--- base/posix/unix_domain_socket_linux.cc.orig	2017-06-05 19:03:00 UTC
+++ base/posix/unix_domain_socket_linux.cc
@@ -23,6 +23,15 @@
 
 namespace base {
 
+#if defined(OS_BSD)
+// Port over Linux ucred structure
+struct ucred {
+  pid_t pid; // process ID of the sending process
+  uid_t uid; // user ID of the sending process
+  gid_t gid; // group ID of the sending process
+};
+#endif
+
 const size_t UnixDomainSocket::kMaxFileDescriptors = 16;
 
 #if !defined(OS_NACL_NONSFI)
@@ -37,8 +46,14 @@ bool CreateSocketPair(ScopedFD* one, ScopedFD* two) {
 
 // static
 bool UnixDomainSocket::EnableReceiveProcessId(int fd) {
+#if defined(OS_BSD)
+  // XXX(rene) do this? :
+  // taken from dbus, Academic Free License 2.1 / GPL 2+
+  return 0; // fake OK
+#else
   const int enable = 1;
   return setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &enable, sizeof(enable)) == 0;
+#endif
 }
 #endif  // !defined(OS_NACL_NONSFI)
 
@@ -144,7 +159,11 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
       // The PNaCl toolchain for Non-SFI binary build does not support
       // SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
+#if defined(OS_BSD)
+        1) { // XXX(rene) carpet getting full ...
+#else
           cmsg->cmsg_type == SCM_CREDENTIALS) {
+#endif
         DCHECK_EQ(payload_len, sizeof(struct ucred));
         DCHECK_EQ(pid, -1);
         pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
