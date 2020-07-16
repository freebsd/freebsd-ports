--- xbmc/platform/linux/input/LibInputHandler.cpp.orig	2020-05-19 20:44:08 UTC
+++ xbmc/platform/linux/input/LibInputHandler.cpp
@@ -115,7 +115,7 @@ void CLibInputHandler::Start()
 
 void CLibInputHandler::Process()
 {
-  int epollFd = epoll_create1(0);
+  int epollFd = epoll_create1(EPOLL_CLOEXEC);
   if (epollFd < 0)
   {
     CLog::Log(LOGERROR, "CLibInputHandler::%s - failed to create epoll file descriptor: %s", __FUNCTION__, strerror(-errno));
