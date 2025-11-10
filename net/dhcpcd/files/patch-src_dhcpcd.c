--- src/dhcpcd.c.orig	2025-06-01 18:40:28 UTC
+++ src/dhcpcd.c
@@ -393,7 +393,7 @@ dhcpcd_daemonise(struct dhcpcd_ctx *ctx)
 
 	eloop_event_delete(ctx->eloop, ctx->fork_fd);
 	exit_code = EXIT_SUCCESS;
-	if (write(ctx->fork_fd, &exit_code, sizeof(exit_code)) == -1)
+	if (send(ctx->fork_fd, &exit_code, sizeof(exit_code), MSG_EOR) == -1)
 		logerr(__func__);
 	close(ctx->fork_fd);
 	ctx->fork_fd = -1;
@@ -1449,8 +1449,8 @@ dhcpcd_signal_cb(int sig, void *arg)
 
 	if (sig != SIGCHLD && ctx->options & DHCPCD_FORKED) {
 		if (sig != SIGHUP &&
-		    write(ctx->fork_fd, &sig, sizeof(sig)) == -1)
-			logerr("%s: write", __func__);
+		    send(ctx->fork_fd, &sig, sizeof(sig), MSG_EOR) == -1)
+			logerr("%s: send", __func__);
 		return;
 	}
 
@@ -2712,8 +2712,8 @@ exit1:
 #ifdef USE_SIGNALS
 	/* If still attached, detach from the launcher */
 	if (ctx.options & DHCPCD_STARTED && ctx.fork_fd != -1) {
-		if (write(ctx.fork_fd, &i, sizeof(i)) == -1)
-			logerr("%s: write", __func__);
+		if (send(ctx.fork_fd, &i, sizeof(i), MSG_EOR) == -1)
+			logerr("%s: send", __func__);
 	}
 #endif
 
