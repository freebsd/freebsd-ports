--- relayd/relayd.c.orig	2010-05-31 07:32:32.670912835 +0000
+++ relayd/relayd.c	2010-05-31 07:35:25.223559078 +0000
@@ -112,6 +112,9 @@
 	case SIGHUP:
 		reconfigure();
 		break;
+	case SIGPIPE:
+		/* ignore */
+		break;
 	default:
 		fatalx("unexpected signal");
 	}
@@ -136,10 +139,6 @@
 	u_int32_t		 opts;
 	struct relayd		*env;
 	const char		*conffile;
-	struct event		 ev_sigint;
-	struct event		 ev_sigterm;
-	struct event		 ev_sigchld;
-	struct event		 ev_sighup;
 	struct imsgev		*iev;
 
 	opts = 0;
@@ -245,15 +244,17 @@
 
 	event_init();
 
-	signal_set(&ev_sigint, SIGINT, main_sig_handler, env);
-	signal_set(&ev_sigterm, SIGTERM, main_sig_handler, env);
-	signal_set(&ev_sigchld, SIGCHLD, main_sig_handler, env);
-	signal_set(&ev_sighup, SIGHUP, main_sig_handler, env);
-	signal_add(&ev_sigint, NULL);
-	signal_add(&ev_sigterm, NULL);
-	signal_add(&ev_sigchld, NULL);
-	signal_add(&ev_sighup, NULL);
-	signal(SIGPIPE, SIG_IGN);
+	signal_set(&env->sc_evsigint, SIGINT, main_sig_handler, env);
+	signal_set(&env->sc_evsigterm, SIGTERM, main_sig_handler, env);
+	signal_set(&env->sc_evsigchld, SIGCHLD, main_sig_handler, env);
+	signal_set(&env->sc_evsighup, SIGHUP, main_sig_handler, env);
+	signal_set(&env->sc_evsigpipe, SIGPIPE, main_sig_handler, env);
+
+	signal_add(&env->sc_evsigint, NULL);
+	signal_add(&env->sc_evsigterm, NULL);
+	signal_add(&env->sc_evsigchld, NULL);
+	signal_add(&env->sc_evsighup, NULL);
+	signal_add(&env->sc_evsigpipe, NULL);
 
 	close(pipe_parent2pfe[1]);
 	close(pipe_parent2hce[1]);
@@ -306,6 +307,8 @@
 #endif
 	event_dispatch();
 
+	main_shutdown(env);
+	/* NOTREACHED */
 	return (0);
 }
 
@@ -626,6 +629,7 @@
 #ifndef __FreeBSD__
 	struct ctl_demote	 demote;
 #endif
+	int			 verbose;
 
 	iev = ptr;
 	ibuf = &iev->ibuf;
@@ -669,6 +673,10 @@
 			 */
 			reconfigure();
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+			log_verbose(verbose);
+			break;
 		default:
 			log_debug("main_dispatch_pfe: unexpected imsg %d",
 			    imsg.hdr.type);
@@ -972,6 +980,7 @@
 	if (timercmp(&tv_next, &tv, >))
 		bcopy(&tv_next, &tv, sizeof(tv));
 
+	event_del(ev);
 	event_set(ev, fd, event, fn, arg);
 	event_add(ev, &tv);
 }
@@ -1129,6 +1138,7 @@
 	}
 	pn->key = strdup(pk->key);
 	if (pn->key == NULL) {
+		free(pn);
 		log_warn("out of memory");
 		return (NULL);
 	}
