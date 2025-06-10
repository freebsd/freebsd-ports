--- src/3rdparty/chromium/base/message_loop/message_pump_epoll.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/base/message_loop/message_pump_epoll.cc
@@ -42,7 +42,7 @@ std::atomic_bool g_use_batched_version = false;
 std::atomic_bool g_use_poll = false;
 
 constexpr std::pair<uint32_t, short int> kEpollToPollEvents[] = {
-    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT}, {EPOLLRDHUP, POLLRDHUP},
+    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT},
     {EPOLLPRI, POLLPRI}, {EPOLLERR, POLLERR}, {EPOLLHUP, POLLHUP}};
 
 void SetEventsForPoll(const uint32_t epoll_events, struct pollfd* poll_entry) {
