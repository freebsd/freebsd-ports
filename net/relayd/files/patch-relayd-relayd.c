--- relayd/relayd.c.orig	2011-01-15 00:27:09.020486320 +0100
+++ relayd/relayd.c	2011-01-15 00:32:43.024188430 +0100
@@ -26,6 +26,7 @@
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
+#include <sys/resource.h>
 
 #include <net/if.h>
 #include <netinet/in.h>
@@ -113,6 +114,9 @@
 	case SIGHUP:
 		reconfigure();
 		break;
+	case SIGPIPE:
+		/* ignore */
+		break;
 	default:
 		fatalx("unexpected signal");
 	}
@@ -142,10 +146,6 @@
 #endif
 	struct relayd		*env;
 	const char		*conffile;
-	struct event		 ev_sigint;
-	struct event		 ev_sigterm;
-	struct event		 ev_sigchld;
-	struct event		 ev_sighup;
 	struct imsgev		*iev;
 
 	opts = 0;
@@ -261,15 +261,17 @@
 
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
@@ -322,6 +324,8 @@
 #endif
 	event_dispatch();
 
+	main_shutdown(env);
+	/* NOTREACHED */
 	return (0);
 }
 
@@ -642,6 +646,7 @@
 #ifndef __FreeBSD__
 	struct ctl_demote	 demote;
 #endif
+	int			 verbose;
 
 	iev = ptr;
 	ibuf = &iev->ibuf;
@@ -685,6 +690,10 @@
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
@@ -988,6 +997,7 @@
 	if (timercmp(&tv_next, &tv, >))
 		bcopy(&tv_next, &tv, sizeof(tv));
 
+	event_del(ev);
 	event_set(ev, fd, event, fn, arg);
 	event_add(ev, &tv);
 }
@@ -1145,6 +1155,7 @@
 	}
 	pn->key = strdup(pk->key);
 	if (pn->key == NULL) {
+		free(pn);
 		log_warn("out of memory");
 		return (NULL);
 	}
@@ -1370,3 +1381,24 @@
 
 	return (0);
 }
+
+void
+socket_rlimit(int maxfd)
+{
+	struct rlimit	 rl;
+
+	if (getrlimit(RLIMIT_NOFILE, &rl) == -1)
+		fatal("socket_rlimit: failed to get resource limit");
+	log_debug("socket_rlimit: max open files %d", rl.rlim_max);
+
+	/*
+	 * Allow the maximum number of open file descriptors for this
+	 * login class (which should be the class "daemon" by default).
+	 */
+	if (maxfd == -1)
+		rl.rlim_cur = rl.rlim_max;
+	else
+		rl.rlim_cur = MAX(rl.rlim_max, (rlim_t)maxfd);
+	if (setrlimit(RLIMIT_NOFILE, &rl) == -1)
+		fatal("socket_rlimit: failed to set resource limit");
+}
