--- src/server.c.orig	Thu Mar  3 10:59:28 2005
+++ src/server.c	Thu Mar  3 10:59:48 2005
@@ -71,7 +71,7 @@
 	case SIGTERM: srv_shutdown = 1; break;
 	case SIGALRM: handle_sig_alarm = 1; break;
 	case SIGHUP:  handle_sig_hup = 1; break;
-	case SIGCLD: break;
+	case SIGCHLD: break;
 	}
 }
 #elif defined(HAVE_SIGNAL) || defined(HAVE_SIGACTION)
@@ -80,7 +80,7 @@
 	case SIGTERM: srv_shutdown = 1; break;
 	case SIGALRM: handle_sig_alarm = 1; break;
 	case SIGHUP:  handle_sig_hup = 1; break;
-	case SIGCLD:  break;
+	case SIGCHLD:  break;
 	}
 }
 #endif
@@ -686,7 +686,7 @@
 	sigaction(SIGTERM, &act, NULL);
 	sigaction(SIGHUP,  &act, NULL);
 	sigaction(SIGALRM, &act, NULL);
-	sigaction(SIGCLD, &act, NULL);
+	sigaction(SIGCHLD, &act, NULL);
 	
 #elif defined(HAVE_SIGNAL)
 	/* ignore the SIGPIPE from sendfile() */
@@ -695,7 +695,7 @@
 	signal(SIGALRM, signal_handler);
 	signal(SIGTERM, signal_handler);
 	signal(SIGHUP,  signal_handler);
-	signal(SIGCLD,  signal_handler);
+	signal(SIGCHLD,  signal_handler);
 #endif
 	
 #ifdef USE_ALARM
