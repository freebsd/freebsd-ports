--- misc/plugutils.c.orig	2025-08-01 11:38:10 UTC
+++ misc/plugutils.c
@@ -74,7 +74,7 @@ add_kb_usage (struct script_infos *args, size_t size)
   kb_usage += size;
   if (kb_usage > max_kb_usage)
     {
-      g_warning ("KB usage exceeded %lu MB. Unable to store any further KB "
+      g_warning ("KB usage exceeded %zu MB. Unable to store any further KB "
                  "Items for script %s",
                  max_kb_usage / 1024 / 1024, args->name);
       return -1;
