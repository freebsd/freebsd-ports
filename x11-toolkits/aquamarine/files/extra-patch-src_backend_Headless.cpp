--- src/backend/Headless.cpp.orig	2026-06-11 16:17:06 UTC
+++ src/backend/Headless.cpp
@@ -232,7 +232,7 @@ void Aquamarine::CHeadlessBackend::updateTimerFD() {
 
     auto       secs = std::chrono::time_point_cast<std::chrono::seconds>(soonestTimer);
     auto       ns   = std::chrono::time_point_cast<std::chrono::nanoseconds>(soonestTimer) - std::chrono::time_point_cast<std::chrono::nanoseconds>(secs);
-    itimerspec ts   = {.it_value = {secs.time_since_epoch().count(), ns.count()}};
+    itimerspec ts   = {.it_value = {sc<time_t>(secs.time_since_epoch().count()), sc<long>(ns.count())}};
 
     if (timerfd_settime(timers.timerfd.get(), TFD_TIMER_ABSTIME, &ts, nullptr))
         backend->log(AQ_LOG_ERROR, std::format("headless: failed to arm timerfd: {}", strerror(errno)));
