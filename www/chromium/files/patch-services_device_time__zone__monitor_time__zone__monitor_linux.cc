--- services/device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2019-01-10 00:39:59.319666000 +0100
+++ services/device/time_zone_monitor/time_zone_monitor_linux.cc	2019-01-10 00:40:51.718178000 +0100
@@ -99,7 +99,11 @@
     // false positives are harmless, assuming the false positive rate is
     // reasonable.
     const char* const kFilesToWatch[] = {
+#if defined(OS_BSD)
+        "/etc/localtime",
+#else
         "/etc/localtime", "/etc/timezone", "/etc/TZ",
+#endif
     };
 
     auto callback =
