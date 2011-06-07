--- ipc/ipc_channel_posix.cc.orig	2011-06-06 00:13:54.367162724 +0300
+++ ipc/ipc_channel_posix.cc	2011-06-06 00:14:09.016163924 +0300
@@ -927,7 +927,7 @@
 
 bool Channel::ChannelImpl::GetClientEuid(uid_t* client_euid) const {
   DCHECK(HasAcceptedConnection());
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   uid_t peer_euid;
   gid_t peer_gid;
   if (getpeereid(pipe_, &peer_euid, &peer_gid) != 0) {
