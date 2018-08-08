--- third_party/perfetto/include/perfetto/base/watchdog_posix.h.orig	2018-08-04 21:15:43.145900000 +0200
+++ third_party/perfetto/include/perfetto/base/watchdog_posix.h	2018-08-04 21:16:02.944049000 +0200
@@ -45,7 +45,7 @@
     Timer(const Timer&) = delete;
     Timer& operator=(const Timer&) = delete;
 
-    timer_t timerid_ = nullptr;
+    timer_t timerid_ = 0;
   };
   virtual ~Watchdog();
 
