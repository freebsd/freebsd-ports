--- libtransmission/session-alt-speeds.cc.orig	2025-10-15 08:50:14 UTC
+++ libtransmission/session-alt-speeds.cc
@@ -3,6 +3,7 @@
 // or any future license endorsed by Mnemosyne LLC.
 // License text can be found in the licenses/ folder.
 
+#include <chrono>
 #include <fmt/chrono.h>
 
 #include "transmission.h"
@@ -105,7 +106,7 @@ void tr_session_alt_speeds::setActive(bool active, Cha
 
 [[nodiscard]] bool tr_session_alt_speeds::isActiveMinute(time_t time) const noexcept
 {
-    auto const tm = fmt::localtime(time);
+    auto const tm = *std::localtime(&time);
 
     size_t minute_of_the_week = tm.tm_wday * MinutesPerDay + tm.tm_hour * MinutesPerHour + tm.tm_min;
 
