--- src/tcsd/svrside.c.orig	2014-12-20 02:37:46 UTC
+++ src/tcsd/svrside.c
@@ -92,20 +92,36 @@ tcsd_signal_term(int signal)
 	term = 1;
 }
 
-void
+static void
 tcsd_signal_hup(int signal)
 {
 	hup = 1;
 }
 
+static void
+tcsd_signal_chld(int signal)
+{
+
+	wait3(NULL, WNOHANG, NULL);
+}
+
 static TSS_RESULT
 signals_init(void)
 {
 	int rc;
 	sigset_t sigmask;
 	struct sigaction sa;
+	struct sigaction tcsd_sa_chld;
 
 	sigemptyset(&sigmask);
+	if ((rc = sigaddset(&sigmask, SIGCHLD))) {
+		LogError("sigaddset: %s", strerror(errno));
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
+	if ((rc = sigaddset(&sigmask, SIGINT))) {
+		LogError("sigaddset: %s", strerror(errno));
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
 	if ((rc = sigaddset(&sigmask, SIGTERM))) {
 		LogError("sigaddset: %s", strerror(errno));
 		return TCSERR(TSS_E_INTERNAL_ERROR);
@@ -128,9 +144,21 @@ signals_init(void)
 		return TCSERR(TSS_E_INTERNAL_ERROR);
 	}
 
+	if ((rc = sigaction(SIGINT, &sa, NULL))) {
+		LogError("signal SIGINT not registered: %s", strerror(errno));
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
+
 	sa.sa_handler = tcsd_signal_hup;	
 	if ((rc = sigaction(SIGHUP, &sa, NULL))) {
 		LogError("signal SIGHUP not registered: %s", strerror(errno));
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
+
+	tcsd_sa_chld.sa_flags = SA_RESTART;
+	tcsd_sa_chld.sa_handler = tcsd_signal_chld;
+	if ((rc = sigaction(SIGCHLD, &tcsd_sa_chld, NULL))) {
+		LogError("signal SIGCHLD not registered: %s", strerror(errno));
 		return TCSERR(TSS_E_INTERNAL_ERROR);
 	}
 
