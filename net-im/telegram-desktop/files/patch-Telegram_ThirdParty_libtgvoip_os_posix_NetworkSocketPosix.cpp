--- Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp.orig	2017-12-27 18:47:58 UTC
+++ Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp
@@ -46,6 +46,7 @@ void NetworkSocketPosix::SetMaxPriority(
 	if(res<0){
 		LOGE("error setting darwin-specific net priority: %d / %s", errno, strerror(errno));
 	}
+#elif defined(__FreeBSD__)
 #else
 	int prio=5;
 	int res=setsockopt(fd, SOL_SOCKET, SO_PRIORITY, &prio, sizeof(prio));
