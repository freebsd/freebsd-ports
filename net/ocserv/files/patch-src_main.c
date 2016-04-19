--- src/main.c.orig	2016-03-06 11:14:35 UTC
+++ src/main.c
@@ -77,7 +77,7 @@ static void listen_watcher_cb (EV_P_ ev_
 
 int syslog_open = 0;
 sigset_t sig_default_set;
-struct ev_loop *loop;
+struct ev_loop *loop = NULL;
 
 /* EV watchers */
 ev_io ctl_watcher;
@@ -147,8 +147,9 @@ int y;
 #elif defined(IP_RECVDSTADDR) /* *BSD */
 	if (family == AF_INET) {
 		y = 1;
-		if (setsockopt(fd, IPPROTO_IP, IP_RECVDSTADDR,
-			       (const void *)&y, sizeof(y)) < 0)
+        if (family == AF_INET &&
+            setsockopt(fd, IPPROTO_IP, IP_RECVDSTADDR,
+                (const void *)&y, sizeof(y)) < 0)
 			perror("setsockopt(IP_RECVDSTADDR) failed");
 	}
 #endif
@@ -661,13 +662,15 @@ void clear_lists(main_server_st *s)
 	ctl_handler_deinit(s);
 	main_ban_db_deinit(s);
 
-	/* clear libev state */
-	ev_io_stop (loop, &ctl_watcher);
-	ev_io_stop (loop, &sec_mod_watcher);
-	ev_child_stop (loop, &child_watcher);
-	ev_timer_stop(loop, &maintainance_watcher);
-	/* free memory by the event loop */
-	ev_loop_destroy (loop);
+	if (loop) {
+		/* clear libev state */
+		ev_io_stop (loop, &ctl_watcher);
+		ev_io_stop (loop, &sec_mod_watcher);
+		ev_child_stop (loop, &child_watcher);
+		ev_timer_stop(loop, &maintainance_watcher);
+		/* free memory by the event loop */
+		ev_loop_destroy (loop);
+	}
 }
 
 /* A UDP fd will not be forwarded to worker process before this number of
@@ -1165,12 +1168,6 @@ int main(int argc, char** argv)
 
 	memset(&creds, 0, sizeof(creds));
 
-	loop = EV_DEFAULT;
-	if (loop == NULL) {
-		fprintf(stderr, "could not initialise libev\n");
-		exit(1);
-	}
-
 	/* main pool */
 	main_pool = talloc_init("main");
 	if (main_pool == NULL) {
@@ -1253,6 +1250,12 @@ int main(int argc, char** argv)
 		exit(1);
 	}
 
+	loop = EV_DEFAULT;
+	if (loop == NULL) {
+		fprintf(stderr, "could not ititialise libev\n");
+		exit(1);
+	}
+
 	mslog(s, NULL, LOG_INFO, "initialized %s", PACKAGE_STRING);
 
 	/* chdir to our chroot directory, to allow opening the sec-mod
