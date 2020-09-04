--- src/manage_sql.c.orig	2017-06-19 13:14:58 UTC
+++ src/manage_sql.c
@@ -58,6 +58,7 @@
 #include <unistd.h>
 #include <sys/time.h>
 #include <grp.h>
+#include <libgen.h>
 
 #include <openvas/base/openvas_string.h>
 #include <openvas/base/openvas_file.h>
@@ -97,7 +98,7 @@ manage_scap_loaded ();
 /**
  * @brief Flag to force authentication to succeed.  For scheduled tasks.
  */
-int authenticate_allow_all;
+extern int authenticate_allow_all;
 
 const char *threat_message_type (const char *);
 
@@ -950,7 +951,7 @@ iso_time_internal (time_t *epoch_time, const char **ab
   static char time_string[100];
 
   tm = localtime (epoch_time);
-  if (timezone == 0)
+  if (tm->tm_gmtoff == 0)
     {
       if (strftime (time_string, 98, "%FT%TZ", tm) == 0)
         return NULL;
@@ -24386,7 +24387,7 @@ report_port_count (report_t report)
 {
   return sql_int ("SELECT count (DISTINCT port) FROM results"
                   " WHERE report = %llu AND port != ''"
-                  "  AND port NOT LIKE 'general/%';",
+                  "  AND port NOT LIKE 'general/%%';",
                   report);
 }
 
@@ -24401,7 +24402,7 @@ prognostic_host_port_count (report_t report, const cha
 {
   return sql_int ("SELECT count (DISTINCT port) FROM results"
                   " WHERE report = %llu AND host = '%s'"
-                  "  AND port NOT LIKE 'general/%';",
+                  "  AND port NOT LIKE 'general/%%';",
                   report,
                   host);
 }
@@ -33237,7 +33238,7 @@ init_otp_pref_iterator (iterator_t* iterator,
                  " WHERE config_preferences.config = %llu"
                  " AND config_preferences.type = '%s'"
                  " AND (config_preferences.name = nvt_preferences.name"
-                 "      OR config_preferences.name LIKE 'timeout.%')"
+                 "      OR config_preferences.name LIKE 'timeout.%%')"
                  " AND config_preferences.name != 'max_checks'"
                  " AND config_preferences.name != 'max_hosts'"
                  " UNION"
@@ -43502,12 +43503,12 @@ modify_schedule (const char *schedule_id, const char *
   if (duration == -1)
     duration_string = NULL;
   else
-    duration_string = g_strdup_printf ("%li", duration);
+    duration_string = g_strdup_printf ("%li", (long)duration);
 
   if (first_time == -1)
     first_time_string = NULL;
   else
-    first_time_string = g_strdup_printf ("%li", first_time);
+    first_time_string = g_strdup_printf ("%li", (long)first_time);
 
   if ((period_months == -1) || (period_months == 0))
     {
@@ -43519,12 +43520,12 @@ modify_schedule (const char *schedule_id, const char *
       else
         {
           period_months_string = g_strdup ("0");
-          period_string = g_strdup_printf ("%li", period);
+          period_string = g_strdup_printf ("%li", (long)period);
         }
     }
   else
     {
-      period_months_string = g_strdup_printf ("%li", period_months);
+      period_months_string = g_strdup_printf ("%li", (long)period_months);
       period_string = g_strdup ("0");
     }
 
