--- src/manage_sql_report_formats.c	2022-07-21 02:20:24.000000000 -0500
+++ src/manage_sql_report_formats.c	2022-10-30 17:34:50.896890000 -0500
@@ -45,7 +45,6 @@
 #include <unistd.h>
 
 #include <gvm/base/gvm_sentry.h>
-#include <bsd/unistd.h>
 #include <gvm/util/uuidutils.h>
 #include <gvm/util/fileutils.h>
 
@@ -2472,7 +2471,7 @@
       case REPORT_FORMAT_PARAM_TYPE_REPORT_FORMAT_LIST:
         {
           if (g_regex_match_simple
-                ("^(?:[[:alnum:]-_]+)?(?:,(?:[[:alnum:]-_])+)*$", value, 0, 0)
+                ("^(?:[[:alnum:]\\-_]+)?(?:,(?:[[:alnum:]\\-_])+)*$", value, 0, 0)
               == FALSE)
             return 1;
           else
