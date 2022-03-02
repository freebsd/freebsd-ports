--- base/posix/unix_domain_socket.cc.orig	2022-02-28 16:54:41 UTC
+++ base/posix/unix_domain_socket.cc
@@ -50,7 +50,7 @@ bool CreateSocketPair(ScopedFD* one, ScopedFD* two) {
 
 // static
 bool UnixDomainSocket::EnableReceiveProcessId(int fd) {
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   const int enable = 1;
   return setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &enable, sizeof(enable)) == 0;
 #else
@@ -140,7 +140,7 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
 
   const size_t kControlBufferSize =
       CMSG_SPACE(sizeof(int) * kMaxFileDescriptors)
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
       // macOS does not support ucred.
       // macOS supports xucred, but this structure is insufficient.
       + CMSG_SPACE(sizeof(struct ucred))
@@ -168,7 +168,7 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
         wire_fds = reinterpret_cast<int*>(CMSG_DATA(cmsg));
         wire_fds_len = payload_len / sizeof(int);
       }
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
       // macOS does not support SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
           cmsg->cmsg_type == SCM_CREDENTIALS) {
@@ -202,6 +202,9 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
     socklen_t pid_size = sizeof(pid);
     if (getsockopt(fd, SOL_LOCAL, LOCAL_PEERPID, &pid, &pid_size) != 0)
       pid = -1;
+#elif BUILDFLAG(IS_BSD)
+    NOTIMPLEMENTED();
+    pid = -1;
 #else
     // |pid| will legitimately be -1 if we read EOF, so only DCHECK if we
     // actually received a message.  Unfortunately, Linux allows sending zero
