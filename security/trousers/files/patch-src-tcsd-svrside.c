--- src/tcsd/svrside.c.orig	2012-09-25 23:23:01.000000000 +0900
+++ src/tcsd/svrside.c	2013-07-31 22:12:08.000000000 +0900
@@ -66,12 +66,19 @@
 	close(sd);
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
@@ -80,6 +87,14 @@
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
@@ -102,12 +117,24 @@
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
 
@@ -256,6 +283,26 @@
 	if ((result = tcsd_startup()))
 		return (int)result;
 
+	pwd = getpwnam(TSS_USER_NAME);
+	if (pwd == NULL) {
+		if (errno == 0) {
+			LogError("User \"%s\" not found, please add this user"
+					" manually.", TSS_USER_NAME);
+		} else {
+			LogError("getpwnam(%s): %s", TSS_USER_NAME, strerror(errno));
+		}
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
+	setuid(pwd->pw_uid);
+
+	if (getenv("TCSD_FOREGROUND") == NULL) {
+		if (daemon(0, 0) == -1) {
+			perror("daemon");
+			tcsd_shutdown();
+			return -1;
+		}
+	}
+
 	sd = socket(AF_INET, SOCK_STREAM, 0);
 	if (sd < 0) {
 		LogError("Failed socket: %s", strerror(errno));
@@ -279,33 +326,12 @@
 		LogError("Failed bind: %s", strerror(errno));
 		return -1;
 	}
-#ifndef SOLARIS
-	pwd = getpwnam(TSS_USER_NAME);
-	if (pwd == NULL) {
-		if (errno == 0) {
-			LogError("User \"%s\" not found, please add this user"
-					" manually.", TSS_USER_NAME);
-		} else {
-			LogError("getpwnam(%s): %s", TSS_USER_NAME, strerror(errno));
-		}
-		return TCSERR(TSS_E_INTERNAL_ERROR);
-	}
-	setuid(pwd->pw_uid);
-#endif
 	if (listen(sd, TCSD_MAX_SOCKETS_QUEUED) < 0) {
 		LogError("Failed listen: %s", strerror(errno));
 		return -1;
 	}
 	client_len = (unsigned)sizeof(client_addr);
 	
-	if (getenv("TCSD_FOREGROUND") == NULL) {
-		if (daemon(0, 0) == -1) {
-			perror("daemon");
-			tcsd_shutdown();
-			return -1;
-		}
-	}
-
 	LogInfo("%s: TCSD up and running.", PACKAGE_STRING);
 	do {
 		newsd = accept(sd, (struct sockaddr *) &client_addr, &client_len);
