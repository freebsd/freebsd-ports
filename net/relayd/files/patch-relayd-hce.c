--- relayd/hce.c.orig	2010-05-31 08:54:55.771055422 +0200
+++ relayd/hce.c	2010-05-31 08:54:50.916277342 +0200
@@ -62,6 +62,11 @@
 	case SIGTERM:
 		hce_shutdown();
 		break;
+	case SIGCHLD:
+	case SIGHUP:
+	case SIGPIPE:
+		/* ignore */
+		break;
 	default:
 		fatalx("hce_sig_handler: unexpected signal");
 	}
@@ -75,8 +80,6 @@
 	pid_t		 pid;
 	struct passwd	*pw;
 	int		 i;
-	struct event	 ev_sigint;
-	struct event	 ev_sigterm;
 
 	switch (pid = fork()) {
 	case -1:
@@ -135,12 +138,17 @@
 	    iev_main->handler, iev_main);
 	event_add(&iev_main->ev, NULL);
 
-	signal_set(&ev_sigint, SIGINT, hce_sig_handler, NULL);
-	signal_set(&ev_sigterm, SIGTERM, hce_sig_handler, NULL);
-	signal_add(&ev_sigint, NULL);
-	signal_add(&ev_sigterm, NULL);
-	signal(SIGPIPE, SIG_IGN);
-	signal(SIGHUP, SIG_IGN);
+	signal_set(&env->sc_evsigint, SIGINT, hce_sig_handler, env);
+	signal_set(&env->sc_evsigterm, SIGTERM, hce_sig_handler, env);
+	signal_set(&env->sc_evsigchld, SIGCHLD, hce_sig_handler, env);
+	signal_set(&env->sc_evsighup, SIGHUP, hce_sig_handler, env);
+	signal_set(&env->sc_evsigpipe, SIGPIPE, hce_sig_handler, env);
+
+	signal_add(&env->sc_evsigint, NULL);
+	signal_add(&env->sc_evsigterm, NULL);
+	signal_add(&env->sc_evsigchld, NULL);
+	signal_add(&env->sc_evsighup, NULL);
+	signal_add(&env->sc_evsigpipe, NULL);
 
 	/* setup pipes */
 	close(pipe_pfe2hce[1]);
@@ -370,6 +378,7 @@
 	objid_t			 id;
 	struct host		*host;
 	struct table		*table;
+	int			 verbose;
 
 	iev = ptr;
 	ibuf = &iev->ibuf;
@@ -437,6 +446,10 @@
 				table->skipped = 0;
 			hce_launch_checks(-1, EV_TIMEOUT, env);
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+			log_verbose(verbose);
+			break;
 		default:
 			log_debug("hce_dispatch_msg: unexpected imsg %d",
 			    imsg.hdr.type);
