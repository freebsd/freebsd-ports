--- src/lnav_log.cc.orig	2018-08-27 14:23:13 UTC
+++ src/lnav_log.cc
@@ -255,7 +255,7 @@ void log_msg(lnav_log_level_t level, const char *src_f
         localtm.tm_sec,
         (int)(curr_time.tv_usec / 1000),
         LEVEL_NAMES[level],
-        basename((char *)src_file),
+        src_file,
         line_number);
     rc = vsnprintf(&line[prefix_size], MAX_LOG_LINE_SIZE - prefix_size,
         fmt, args);
