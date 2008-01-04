--- src/event.h	2003-05-02 22:44:12.000000000 -0400
+++ src/event.h	2007-08-12 00:13:44.000000000 -0400
@@ -19,6 +19,11 @@
 #include <sys/types.h>
 #include <sys/time.h>
 
+struct pcap_timeval {
+    u_int32_t tv_sec;      /* seconds */
+    u_int32_t tv_usec;     /* microseconds */
+};
+
 typedef struct _Event
 {
     u_int32_t sig_generator;   /* which part of snort generated the alert? */
@@ -30,6 +35,7 @@
     u_int32_t event_reference; /* reference to other events that have gone off,
                                 * such as in the case of tagged packets...
                                 */
-    struct timeval ref_time;   /* reference time for the event reference */
+    // struct timeval ref_time;   /* reference time for the event reference */
+    struct pcap_timeval ref_time;   /* reference time for the event reference */
 } Event;
 #endif /* __EVENT_H__ */
