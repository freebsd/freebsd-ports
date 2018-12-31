--- Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp.orig	2018-11-23 01:03:16 UTC
+++ Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp
@@ -61,6 +61,7 @@ void NetworkSocketPosix::SetMaxPriority(
 	if(res<0){
 		LOGE("error setting darwin-specific net priority: %d / %s", errno, strerror(errno));
 	}
+#elif defined(__FreeBSD__)
 #elif defined(__linux__)
 	int prio=6;
 	int res=setsockopt(fd, SOL_SOCKET, SO_PRIORITY, &prio, sizeof(prio));
