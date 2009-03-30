--- src/kit/kit-spawn.c.orig	2009-03-29 20:11:24.000000000 -0400
+++ src/kit/kit-spawn.c	2009-03-29 20:11:43.000000000 -0400
@@ -396,7 +396,10 @@ kit_spawn_sync (const char     *working_
                         }
                 }
 
+again:
                 if (waitpid (pid, out_exit_status, 0) == -1) {
+			if (errno == EINTR)
+				goto again;
                         goto out;
                 }
                 pid = -1;
