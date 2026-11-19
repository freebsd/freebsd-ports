--- base/message_loop/message_pump_epoll.cc.orig	2026-11-19 12:25:27 UTC
+++ base/message_loop/message_pump_epoll.cc
@@ -41,7 +41,7 @@ std::atomic_bool g_use_batched_version = false;
 std::atomic_bool g_use_poll = false;
 
 constexpr std::pair<uint32_t, short int> kEpollToPollEvents[] = {
-    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT}, {EPOLLRDHUP, POLLRDHUP},
+    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT},
     {EPOLLPRI, POLLPRI}, {EPOLLERR, POLLERR}, {EPOLLHUP, POLLHUP}};
 
 void SetEventsForPoll(const uint32_t epoll_events, struct pollfd* poll_entry) {
