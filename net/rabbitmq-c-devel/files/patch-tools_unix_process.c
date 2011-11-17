--- ./tools/unix/process.c.orig	2011-09-06 09:43:42.000000000 +0100
+++ ./tools/unix/process.c	2011-11-17 15:30:00.000000000 +0000
@@ -38,7 +38,9 @@
 
 #include <unistd.h>
 #include <errno.h>
+#ifdef HAVE_SPAWN_H
 #include <spawn.h>
+#endif
 #include <sys/wait.h>
 
 #include "common.h"
@@ -46,6 +48,7 @@
 
 extern char **environ;
 
+#ifdef HAVE_SPAWN_H
 void pipeline(const char *const *argv, struct pipeline *pl)
 {
 	posix_spawn_file_actions_t file_acts;
@@ -75,6 +78,36 @@
 
 	pl->infd = pipefds[1];
 }
+#else
+void pipeline(const char * const *argv, struct pipeline *pl)
+{
+       int pipefds[2];
+       if (pipe(pipefds))
+               die_errno(errno, "pipe");
+
+       pl->pid = fork();
+
+       if (pl->pid == -1)
+               die_errno(errno, "fork: %s", argv[0]);
+       else
+       if (pl->pid == 0) {
+               if (dup2(pipefds[0], 0))
+                       die_errno(errno, "dup2()");
+               if (close(pipefds[0]))
+                       die_errno(errno, "close()");
+               if (close(pipefds[1]))
+                       die_errno(errno, "close()");
+               execvp(argv[0], argv);
+               die_errno(errno, "execvp()");
+       }
+       else {
+               if (close(pipefds[0]))
+                       die_errno(errno, "close");
+       }
+
+       pl->infd = pipefds[1];
+}
+#endif
 
 int finish_pipeline(struct pipeline *pl)
 {
