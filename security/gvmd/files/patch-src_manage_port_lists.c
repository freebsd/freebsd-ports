--- src/manage_port_lists.c	2022-10-30 17:18:04.068398000 -0500
+++ src/manage_port_lists.c	2022-10-30 17:18:35.850793000 -0500
@@ -252,7 +252,7 @@
 
   split = g_regex_split_simple
            (/* Full-and-Fast--daba56c8-73ec-11df-a475-002264764cea.xml */
-            "^.*([0-9a-f]{8})-([0-9a-f]{4})-([0-9a-f]{4})-([0-9a-f]{4})-([0-9a-f]{12}).xml$",
+            "^.*([0-9a-f]{8})\\-([0-9a-f]{4})\\-([0-9a-f]{4})\\-([0-9a-f]{4})\\-([0-9a-f]{12}).xml$",
             path, 0, 0);
 
   if (split == NULL || g_strv_length (split) != 7)
