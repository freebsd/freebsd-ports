--- src/output-plugins/spo_alert_test.c.orig	2018-10-06 12:25:46 UTC
+++ src/output-plugins/spo_alert_test.c
@@ -317,7 +317,7 @@ SpoAlertTestData * ParseAlertTestArgs(ch
                         filename_end--;
 
                     filename_end++;
-                    filename_end = '\0';
+                    *filename_end = '\0';
 
                     outfile = ProcessFileOption(barnyard2_conf_for_parsing, filename);
                     data->file = OpenAlertFile(outfile);
