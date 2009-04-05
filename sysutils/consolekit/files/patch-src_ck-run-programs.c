--- src/ck-run-programs.c.orig	2009-04-04 20:55:11.000000000 -0400
+++ src/ck-run-programs.c	2009-04-04 20:55:39.000000000 -0400
@@ -225,6 +225,7 @@ ck_run_programs (const char *dirpath,
         out_loop:
                 g_free (child_argv[0]);
         }
+        g_dir_close (dir);
 out:
         g_strfreev (env_for_child);
 }
