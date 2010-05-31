--- relayd/pfe.c.orig	2010-05-31 09:07:56.755288041 +0200
+++ relayd/pfe.c	2010-05-31 09:07:52.006100566 +0200
@@ -62,6 +62,11 @@
 	case SIGTERM:
 		pfe_shutdown();
 		break;
+	case SIGCHLD:
+	case SIGHUP:
+	case SIGPIPE:
+		/* ignore */
+		break;
 	default:
 		fatalx("pfe_sig_handler: unexpected signal");
 	}
@@ -74,8 +79,6 @@
 {
 	pid_t		 pid;
 	struct passwd	*pw;
-	struct event	 ev_sigint;
-	struct event	 ev_sigterm;
 	int		 i;
 	size_t		 size;
 
@@ -121,12 +124,17 @@
 
 	event_init();
 
-	signal_set(&ev_sigint, SIGINT, pfe_sig_handler, NULL);
-	signal_set(&ev_sigterm, SIGTERM, pfe_sig_handler, NULL);
-	signal_add(&ev_sigint, NULL);
-	signal_add(&ev_sigterm, NULL);
-	signal(SIGPIPE, SIG_IGN);
-	signal(SIGHUP, SIG_IGN);
+	signal_set(&env->sc_evsigint, SIGINT, pfe_sig_handler, env);
+	signal_set(&env->sc_evsigterm, SIGTERM, pfe_sig_handler, env);
+	signal_set(&env->sc_evsigchld, SIGCHLD, pfe_sig_handler, env);
+	signal_set(&env->sc_evsighup, SIGHUP, pfe_sig_handler, env);
+	signal_set(&env->sc_evsigpipe, SIGPIPE, pfe_sig_handler, env);
+
+	signal_add(&env->sc_evsigint, NULL);
+	signal_add(&env->sc_evsigterm, NULL);
+	signal_add(&env->sc_evsigchld, NULL);
+	signal_add(&env->sc_evsighup, NULL);
+	signal_add(&env->sc_evsigpipe, NULL);
 
 	/* setup pipes */
 	close(pipe_pfe2hce[0]);
