--- src/fsearch_time_utils.c.orig	2022-08-22 10:06:20 UTC
+++ src/fsearch_time_utils.c
@@ -1,11 +1,11 @@
 #define _GNU_SOURCE
 
-#include "fsearch_time_utils.h"
-
 #include <glib.h>
 #include <stdint.h>
 #include <time.h>
 
+#include "fsearch_time_utils.h"
+
 typedef enum FsearchDateTimeType {
     FSEARCH_DATE_TIME_TYPE_SECOND,
     FSEARCH_DATE_TIME_TYPE_MINUTE,
@@ -377,7 +377,7 @@ parse_implicit_date_time_constants(const char *str, st
 }
 
 static bool
-parse_date_time_constants(const char *str, time_t *time_start_out, time_t *time_end_out) {
+parse_date_time_constants(const char *str, int64_t *time_start_out, int64_t *time_end_out) {
     struct tm tm_start = {};
     struct tm tm_end = {};
 
@@ -469,7 +469,7 @@ round_down_tm_to_reference_with_date_time_accuracy(str
 }
 
 bool
-fsearch_date_time_parse_interval(const char *str, time_t *time_start_out, time_t *time_end_out) {
+fsearch_date_time_parse_interval(const char *str, int64_t *time_start_out, int64_t *time_end_out) {
     if (parse_date_time_constants(str, time_start_out, time_end_out)) {
         return true;
     }
