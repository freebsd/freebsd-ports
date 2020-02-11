From 54efe337993b5571728a09b247c7f39d493659a8 Mon Sep 17 00:00:00 2001
From: Nicholas Marriott <nicholas.marriott@gmail.com>
Date: Wed, 18 Dec 2019 15:58:06 +0000
Subject: [PATCH] Add back utempter code, reported by Peter Schellenbach.

--- spawn.c.orig	2019-12-01 08:47:31 UTC
+++ spawn.c
@@ -424,6 +424,15 @@ spawn_pane(struct spawn_context *sc, char **cause)
 	_exit(1);
 
 complete:
+#ifdef HAVE_UTEMPTER
+	if (~new_wp->flags & PANE_EMPTY) {
+		xasprintf(&cp, "tmux(%lu).%%%u", (long)getpid(), new_wp->id);
+		utempter_add_record(new_wp->fd, cp);
+		kill(getpid(), SIGCHLD);
+		free(cp);
+	}
+#endif
+
 	new_wp->pipe_off = 0;
 	new_wp->flags &= ~PANE_EXITED;
 
