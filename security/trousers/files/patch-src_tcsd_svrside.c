--- src/tcsd/svrside.c.orig	2016-06-20 15:21:26 UTC
+++ src/tcsd/svrside.c
@@ -92,12 +92,19 @@ tcsd_signal_term(int signal)
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
@@ -106,6 +113,14 @@ signals_init(void)
 	struct sigaction sa;
 
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
@@ -128,12 +143,24 @@ signals_init(void)
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
 		return TCSERR(TSS_E_INTERNAL_ERROR);
 	}
 
+	sa.sa_flags = SA_RESTART;
+	sa.sa_handler = tcsd_signal_chld;
+	if ((rc = sigaction(SIGCHLD, &tcsd_sa_chld, NULL))) {
+		LogError("signal SIGCHLD not registered: %s", strerror(errno));
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
+
 	return TSS_SUCCESS;
 }
 
