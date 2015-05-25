--- base/posix/unix_domain_socket_linux.cc.orig	2015-05-13 18:23:01.000000000 -0400
+++ base/posix/unix_domain_socket_linux.cc 2015-05-20 09:09:12.131544000 -0400
@@ -21,6 +21,15 @@
 #include <sys/uio.h>
 #endif
 
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
 
 #if !defined(OS_NACL_NONSFI)
@@ -39,7 +48,13 @@
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
 #endif  // !defined(OS_NACL_NONSFI)
 
@@ -145,7 +160,11 @@
       // The PNaCl toolchain for Non-SFI binary build does not support
       // SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
+#if defined(__FreeBSD__)
+        1) { // XXX(rene) carpet getting full ...
+#else
           cmsg->cmsg_type == SCM_CREDENTIALS) {
+#endif
         DCHECK_EQ(payload_len, sizeof(struct ucred));
         DCHECK_EQ(pid, -1);
         pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
