--- e2fsprogs-1.35/e2fsck/unix.c~	Sun Dec  7 18:11:38 2003
+++ e2fsprogs-1.35/e2fsck/unix.c	Tue Feb 24 22:13:52 2004
@@ -416,6 +416,24 @@
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
 
 static void reserve_stdio_fds(void)
@@ -448,6 +466,17 @@
 	ctx->progress_fd = 0;
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
@@ -740,6 +769,8 @@
 	sigaction(SIGUSR1, &sa, 0);
 	sa.sa_handler = signal_progress_off;
 	sigaction(SIGUSR2, &sa, 0);
+	sa.sa_handler = signal_progress_now;
+	sigaction(SIGINFO, &sa, 0);
 #endif
 
 	/* Update our PATH to include /sbin if we need to run badblocks  */
