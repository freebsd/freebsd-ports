--- src/3rdparty/chromium/base/posix/unix_domain_socket_linux.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/base/posix/unix_domain_socket_linux.cc
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
 namespace base {
 
 const size_t UnixDomainSocket::kMaxFileDescriptors = 16;
@@ -41,7 +50,13 @@ static bool CreateSocketPair(ScopedFD* one, ScopedFD* 
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
 
@@ -147,7 +162,11 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
       // The PNaCl toolchain for Non-SFI binary build does not support
       // SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
+#if defined(__FreeBSD__)
+          1) {
+#else
           cmsg->cmsg_type == SCM_CREDENTIALS) {
+#endif
         DCHECK_EQ(payload_len, sizeof(struct ucred));
         DCHECK_EQ(pid, -1);
         pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
