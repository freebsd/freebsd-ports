--- third_party/perfetto/include/perfetto/base/watchdog_posix.h.orig	2019-03-11 22:08:02 UTC
+++ third_party/perfetto/include/perfetto/base/watchdog_posix.h
@@ -46,7 +46,7 @@ class Watchdog {
     Timer(const Timer&) = delete;
     Timer& operator=(const Timer&) = delete;
 
-    timer_t timerid_ = nullptr;
+    timer_t timerid_ = 0;
   };
   virtual ~Watchdog();
 
