--- src/manage_sql.c.orig	2016-02-26 13:38:52 UTC
+++ src/manage_sql.c
@@ -58,6 +58,7 @@
 #include <unistd.h>
 #include <sys/time.h>
 #include <grp.h>
+#include <libgen.h>
 
 #include <openvas/base/openvas_string.h>
 #include <openvas/base/openvas_file.h>
@@ -940,7 +941,7 @@ iso_time_internal (time_t *epoch_time, c
   static char time_string[100];
 
   tm = localtime (epoch_time);
-  if (timezone == 0)
+  if (tm->tm_gmtoff == 0)
     {
       if (strftime (time_string, 98, "%FT%TZ", tm) == 0)
         return NULL;
@@ -42378,12 +42379,12 @@ modify_schedule (const char *schedule_id
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
@@ -42395,12 +42396,12 @@ modify_schedule (const char *schedule_id
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
 
