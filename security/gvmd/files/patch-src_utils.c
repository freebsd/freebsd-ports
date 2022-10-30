--- src/utils.c	2022-07-21 02:20:24.000000000 -0500
+++ src/utils.c	2022-10-30 17:36:49.935808000 -0500
@@ -34,7 +34,7 @@
 /**
  * @brief Needed for nanosleep.
  */
-#define _POSIX_C_SOURCE 199309L
+//#define _POSIX_C_SOURCE 199309L
 
 #include "utils.h"
 
@@ -339,7 +339,7 @@
   epoch_time = 0;
 
   if (regex == NULL)
-    regex = g_regex_new ("^([0-9]{4}-[0-9]{2}-[0-9]{2})"
+    regex = g_regex_new ("^([0-9]{4}\\-[0-9]{2}\\-[0-9]{2})"
                          "[T ]([0-9]{2}:[0-9]{2})"
                          "(:[0-9]{2})?(?:\\.[0-9]+)?"
                          "(Z|[+-][0-9]{2}:?[0-9]{2})?$",
