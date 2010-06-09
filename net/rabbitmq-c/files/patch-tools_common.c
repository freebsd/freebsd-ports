--- ./tools/common.c.orig	2010-03-31 03:28:20.000000000 +0200
+++ ./tools/common.c	2010-06-01 13:26:57.576932723 +0200
@@ -58,7 +58,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef HAVE_SPAWN_H
 #include <spawn.h>
+#endif
 #include <sys/wait.h>
 
 #include <popt.h>
@@ -327,6 +329,7 @@
 	}
 }
 
+#ifdef HAVE_SPAWN_H
 void pipeline(const char * const *argv, struct pipeline *pl)
 {
 	posix_spawn_file_actions_t file_acts;
@@ -356,6 +359,36 @@
 
 	pl->infd = pipefds[1];
 }
+#else
+void pipeline(const char * const *argv, struct pipeline *pl)
+{
+	int pipefds[2];
+	if (pipe(pipefds))
+		die_errno(errno, "pipe");
+
+	pl->pid = fork();
+
+	if (pl->pid == -1)
+		die_errno(errno, "fork: %s", argv[0]);
+	else
+	if (pl->pid == 0) {
+		if (dup2(pipefds[0], 0))
+			die_errno(errno, "dup2()");
+		if (close(pipefds[0]))
+			die_errno(errno, "close()");
+		if (close(pipefds[1]))
+			die_errno(errno, "close()");
+		execvp(argv[0], argv);
+		die_errno(errno, "execvp()");
+	}
+	else {
+		if (close(pipefds[0]))
+			die_errno(errno, "close");
+	}
+
+	pl->infd = pipefds[1];
+}
+#endif
 
 int finish_pipeline(struct pipeline *pl)
 {
