--- Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp.orig	2017-07-06 17:16:18 UTC
+++ Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp
@@ -45,6 +45,7 @@ void NetworkSocketPosix::SetMaxPriority(
 	if(res<0){
 		LOGE("error setting darwin-specific net priority: %d / %s", errno, strerror(errno));
 	}
+#elif defined(__FreeBSD__)
 #else
 	int prio=5;
 	int res=setsockopt(fd, SOL_SOCKET, SO_PRIORITY, &prio, sizeof(prio));
