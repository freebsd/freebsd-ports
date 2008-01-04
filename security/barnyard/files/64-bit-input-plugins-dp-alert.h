--- src/input-plugins/dp_alert.h	2004-02-19 20:59:48.000000000 -0500
+++ src/input-plugins/dp_alert.h	2007-08-11 23:24:25.000000000 -0400
@@ -34,7 +34,8 @@
 typedef struct _UnifiedAlertRecord
 {
     Event event;
-    struct timeval ts;         /* event timestamp */
+    // struct timeval ts;         /* event timestamp */
+    struct pcap_timeval ts;         /* event timestamp */
     u_int32_t sip;             /* src ip */
     u_int32_t dip;             /* dest ip */
     u_int16_t sp;              /* src port */
