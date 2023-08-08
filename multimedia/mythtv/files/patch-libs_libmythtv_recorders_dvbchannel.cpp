--- libs/libmythtv/recorders/dvbchannel.cpp.orig	2023-05-09 18:32:34 UTC
+++ libs/libmythtv/recorders/dvbchannel.cpp
@@ -1589,7 +1589,7 @@ bool DVBChannel::WaitForBackend(std::chrono::milliseco
     const int fd  = m_fdFrontend;
     auto seconds = duration_cast<std::chrono::seconds>(timeout_ms);
     auto usecs = duration_cast<std::chrono::microseconds>(timeout_ms) - seconds;
-    struct timeval select_timeout = { seconds.count(), usecs.count()};
+    struct timeval select_timeout = { seconds.count(), static_cast<suseconds_t>(usecs.count())};
     fd_set fd_select_set;
     FD_ZERO(    &fd_select_set); // NOLINT(readability-isolate-declaration)
     FD_SET (fd, &fd_select_set);
