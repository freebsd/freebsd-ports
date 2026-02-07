--- plugins/datetime/system-timezone.c.orig	2025-07-10 21:28:09 UTC
+++ plugins/datetime/system-timezone.c
@@ -547,11 +547,19 @@ recursive_compare (struct stat  *localtime_stat,
                    CompareFiles  compare_func)
 {
         struct stat file_stat;
+        char *relpath = NULL;
 
         if (g_stat (file, &file_stat) != 0)
                 return NULL;
 
         if (S_ISREG (file_stat.st_mode)) {
+                relpath = system_timezone_strip_path_if_valid (file);
+                if (g_strstr_len (relpath, -1, "/") == NULL) {
+                        g_free (relpath);
+                        return NULL;
+                }
+                g_free (relpath);
+
                 if (compare_func (localtime_stat,
                                   &file_stat,
                                   localtime_content,
