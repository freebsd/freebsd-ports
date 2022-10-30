--- src/manage_report_formats.c	2022-10-30 17:19:27.476854000 -0500
+++ src/manage_report_formats.c	2022-10-30 17:19:55.531658000 -0500
@@ -612,7 +612,7 @@
 
   split = g_regex_split_simple
            (/* Full-and-Fast--daba56c8-73ec-11df-a475-002264764cea.xml */
-            "^.*([0-9a-f]{8})-([0-9a-f]{4})-([0-9a-f]{4})-([0-9a-f]{4})-([0-9a-f]{12}).xml$",
+            "^.*([0-9a-f]{8})\\-([0-9a-f]{4})\\-([0-9a-f]{4})\\-([0-9a-f]{4})\\-([0-9a-f]{12}).xml$",
             path, 0, 0);
 
   if (split == NULL || g_strv_length (split) != 7)
