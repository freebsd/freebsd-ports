// SIGINFO is a Berkeley extension, so we need to
// remove the #define _XOPEN_SOURCE 600
// It would hide all non-POSIX declarations, including SIGINFO.

--- e2fsck/unix.c.orig	2024-05-21 02:52:47 UTC
+++ e2fsck/unix.c
@@ -9,8 +9,6 @@
  * %End-Header%
  */
 
-#define _XOPEN_SOURCE 600 /* for inclusion of sa_handler in Solaris */
-
 #include "config.h"
 #include <stdio.h>
 #ifdef HAVE_STDLIB_H
@@ -37,7 +35,7 @@ extern int optind;
 #include <sys/ioctl.h>
 #endif
 #ifdef HAVE_MALLOC_H
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
@@ -608,6 +606,24 @@ static int e2fsck_update_progress(e2fsck_t ctx, int pa
 	return 0;
 }
 
+static int e2fsck_progress_once(e2fsck_t ctx, int pass, unsigned long cur, unsigned long max)
+{
+	char buf[80];
+	float percent;
+
+	if (pass == 0)
+		return 0;
+	
+	percent = calc_percent(&e2fsck_tbl, pass, cur, max);
+	e2fsck_simple_progress(ctx, ctx->device_name,
+			percent, 0);
+
+	printf("\n");
+	ctx->progress = 0;
+	return 0;
+}
+
+
 #define PATH_SET "PATH=/sbin"
 
 /*
@@ -641,6 +657,17 @@ static void signal_progress_on(int sig EXT2FS_ATTR((un
 	ctx->progress = e2fsck_update_progress;
 }
 
+static void signal_progress_now(int sig EXT2FS_ATTR((unused)))
+{
+	e2fsck_t ctx = e2fsck_global_ctx;
+
+	if (!ctx)
+		return;
+
+	ctx->progress = e2fsck_progress_once;
+	ctx->progress_fd = 0;
+}
+
 static void signal_progress_off(int sig EXT2FS_ATTR((unused)))
 {
 	e2fsck_t ctx = e2fsck_global_ctx;
@@ -1127,6 +1154,10 @@ static errcode_t PRS(int argc, char *argv[], e2fsck_t 
 	sigaction(SIGUSR1, &sa, 0);
 	sa.sa_handler = signal_progress_off;
 	sigaction(SIGUSR2, &sa, 0);
+	sa.sa_handler = signal_progress_now;
+	if (!getenv("e2fsprogs_inhibit_SIGINFO")) {
+		sigaction(SIGINFO, &sa, 0);
+	}
 #endif
 
 	/* Update our PATH to include /sbin if we need to run badblocks  */
