--- epan/dissectors/packet-its.c.orig	2025-10-14 14:35:47 UTC
+++ epan/dissectors/packet-its.c
@@ -23047,7 +23047,7 @@ its_timestamp_fmt(char *s, uint64_t v)
 static void
 its_timestamp_fmt(char *s, uint64_t v)
 {
-  time_t secs = v / 1000 + 1072915200 - 5;
+  time_t secs = (time_t) ((time_t)v / 1000 + 1072915200 - 5);
   struct tm *tm = gmtime(&secs);
   snprintf(s, ITEM_LABEL_LENGTH, "%u-%02u-%02u %02u:%02u:%02u.%03u (%" PRIu64 ")",
     tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, (uint32_t)(v % 1000), v
