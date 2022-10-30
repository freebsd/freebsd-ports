--- src/manage_configs.c	2022-10-30 17:15:56.559846000 -0500
+++ src/manage_configs.c	2022-10-30 17:17:03.298223000 -0500
@@ -316,7 +316,7 @@
 
   split = g_regex_split_simple
            (/* Full-and-Fast--daba56c8-73ec-11df-a475-002264764cea.xml */
-            "^.*([0-9a-f]{8})-([0-9a-f]{4})-([0-9a-f]{4})-([0-9a-f]{4})-([0-9a-f]{12}).xml$",
+            "^.*([0-9a-f]{8})\\-([0-9a-f]{4})\\-([0-9a-f]{4})\\-([0-9a-f]{4})\\-([0-9a-f]{12}).xml$",
             path, 0, 0);
 
   if (split == NULL || g_strv_length (split) != 7)
