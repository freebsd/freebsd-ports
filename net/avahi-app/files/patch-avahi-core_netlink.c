--- avahi-core/netlink.c.orig	2015-10-10 00:20:03 UTC
+++ avahi-core/netlink.c
@@ -50,8 +50,9 @@ int avahi_netlink_work(AvahiNetlink *nl, int block) {
     struct ucred *cred;
     struct iovec iov;
     struct nlmsghdr *p;
+#ifdef SO_PASSCRED
     char cred_msg[CMSG_SPACE(sizeof(struct ucred))];
-
+#endif
     assert(nl);
 
     iov.iov_base = nl->buffer;
@@ -61,8 +62,10 @@ int avahi_netlink_work(AvahiNetlink *nl, int block) {
     smsg.msg_namelen = 0;
     smsg.msg_iov = &iov;
     smsg.msg_iovlen = 1;
+#ifdef SO_PASSCRED
     smsg.msg_control = cred_msg;
     smsg.msg_controllen = sizeof(cred_msg);
+#endif
     smsg.msg_flags = (block ? 0 : MSG_DONTWAIT);
 
     if ((bytes = recvmsg(nl->fd, &smsg, 0)) < 0) {
@@ -74,7 +77,7 @@ int avahi_netlink_work(AvahiNetlink *nl, int block) {
     }
 
     cmsg = CMSG_FIRSTHDR(&smsg);
-
+#ifdef SO_PASSCRED
     if (!cmsg || cmsg->cmsg_type != SCM_CREDENTIALS) {
         avahi_log_warn("No sender credentials received, ignoring data.");
         return -1;
@@ -84,7 +87,7 @@ int avahi_netlink_work(AvahiNetlink *nl, int block) {
 
     if (cred->pid != 0)
         return -1;
-
+#endif
     p = (struct nlmsghdr *) nl->buffer;
 
     assert(nl->callback);
@@ -134,12 +137,12 @@ AvahiNetlink *avahi_netlink_new(const AvahiPoll *poll_
         avahi_log_error(__FILE__": bind(): %s", strerror(errno));
         goto fail;
     }
-
+#ifdef SO_PASSCRED
     if (setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &on, sizeof(on)) < 0) {
         avahi_log_error(__FILE__": SO_PASSCRED: %s", strerror(errno));
         goto fail;
     }
-
+#endif
     if (!(nl = avahi_new(AvahiNetlink, 1))) {
         avahi_log_error(__FILE__": avahi_new() failed.");
         goto fail;
