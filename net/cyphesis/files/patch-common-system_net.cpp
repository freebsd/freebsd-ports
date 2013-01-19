--- common/system_net.cpp.orig	2012-12-18 19:51:32.000000000 +0100
+++ common/system_net.cpp	2012-12-19 08:49:52.000000000 +0100
@@ -28,6 +28,7 @@
 #endif // _WIN32
 
 #include <cassert>
+#include <cstdio>
 
 extern "C" {
 #ifdef HAVE_SYS_UTSNAME_H
@@ -80,6 +81,14 @@
 #ifdef HAVE_SYS_UN_H
 #ifndef __APPLE__
 #ifndef SO_PEERCRED
+    size_t creds_size;
+
+#if defined (SCM_CREDENTIALS)
+    creds_size = sizeof(struct ucred);
+#elif defined (SCM_CREDS)
+    creds_size = sizeof(struct cmsgcred);
+#endif
+
     // Prove to the server that we are real.
 
     unsigned char buf[1];
@@ -97,12 +106,13 @@
     auth_message.msg_iovlen = 1;
     auth_message.msg_name = 0;
     auth_message.msg_namelen = 0;
-    auth_message.msg_controllen = CMSG_SPACE(sizeof(struct ucred));
+    auth_message.msg_controllen = CMSG_SPACE(creds_size);
     unsigned char * mcb = new unsigned char[auth_message.msg_controllen];
     auth_message.msg_control = mcb;
     auth_message.msg_flags = 0;
 
     struct cmsghdr * control = CMSG_FIRSTHDR(&auth_message);
+#if defined (SCM_CREDENTIALS)
     control->cmsg_len = CMSG_LEN(sizeof(struct ucred));
     control->cmsg_level = SOL_SOCKET;
     control->cmsg_type = SCM_CREDENTIALS;
@@ -110,8 +120,17 @@
     creds->pid = ::getpid();
     creds->uid = ::getuid();
     creds->gid = ::getgid();
+#elif defined (SCM_CREDS)
+    control->cmsg_len = CMSG_LEN(sizeof(struct cmsgcred));
+    control->cmsg_level = SOL_SOCKET;
+    control->cmsg_type = SCM_CREDS;
+    struct cmsgcred  * creds = (struct cmsgcred *)CMSG_DATA(control);
+    creds->cmcred_pid = ::getpid();
+    creds->cmcred_uid = ::getuid();
+    creds->cmcred_gid = ::getgid();
+#endif
 
-    int serr = sendmsg(m_fd, &auth_message, 0);
+    int serr = sendmsg(fd, &auth_message, 0);
 
     delete [] mcb;
 
