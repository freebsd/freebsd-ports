--- base/message_loop/message_pump_epoll.h.orig	2025-12-10 15:04:57 UTC
+++ base/message_loop/message_pump_epoll.h
@@ -51,7 +51,11 @@ namespace base {
 // every call, don't do it when we have too many FDs.
 BASE_FEATURE(kUsePollForMessagePumpEpoll,
              "UsePollForMessagePumpEpoll",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 // A MessagePump implementation suitable for I/O message loops on Linux-based
 // systems with epoll API support.
