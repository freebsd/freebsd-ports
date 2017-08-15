--- src/manage_sql.c	2017-06-20 01:32:02.000000000 -0500
+++ src/manage_sql.c	2017-08-05 21:19:08.663354000 -0500
@@ -57,6 +57,7 @@
 #include <unistd.h>
 #include <sys/time.h>
 #include <grp.h>
+#include <libgen.h>
 
 #include <openvas/base/openvas_string.h>
 #include <openvas/base/openvas_file.h>
@@ -1061,7 +1062,7 @@
   static char time_string[100];
 
   tm = localtime (epoch_time);
-  if (timezone == 0)
+  if (tm->tm_gmtoff == 0)
     {
       if (strftime (time_string, 98, "%FT%TZ", tm) == 0)
         return NULL;
@@ -25384,7 +25385,7 @@
 {
   return sql_int ("SELECT count (DISTINCT port) FROM results"
                   " WHERE report = %llu AND port != ''"
-                  "  AND port NOT %s 'general/%';",
+                  "  AND port NOT %s 'general/%%';",
                   report,
                   sql_ilike_op ());
 }
@@ -25400,7 +25401,7 @@
 {
   return sql_int ("SELECT count (DISTINCT port) FROM results"
                   " WHERE report = %llu AND host = '%s'"
-                  "  AND port NOT %s 'general/%';",
+                  "  AND port NOT %s 'general/%%';",
                   report,
                   host,
                   sql_ilike_op ());
@@ -35110,7 +35111,7 @@
                  " WHERE config_preferences.config = %llu"
                  " AND config_preferences.type = '%s'"
                  " AND (config_preferences.name = nvt_preferences.name"
-                 "      OR config_preferences.name LIKE 'timeout.%')"
+                 "      OR config_preferences.name LIKE 'timeout.%%')"
                  " AND config_preferences.name != 'max_checks'"
                  " AND config_preferences.name != 'max_hosts'"
                  " UNION"
@@ -47821,12 +47822,12 @@
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
@@ -47838,12 +47839,12 @@
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
 
