--- src/tcsd/svrside.c.orig	2010-06-10 05:19:00.000000000 +0900
+++ src/tcsd/svrside.c	2010-10-24 21:04:04.838555802 +0900
@@ -20,7 +20,6 @@
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <netdb.h>
-#include <pwd.h>
 #if (defined (__OpenBSD__) || defined (__FreeBSD__))
 #include <netinet/in.h>
 #endif
@@ -41,11 +40,9 @@
 
 struct tcsd_config tcsd_options;
 struct tpm_properties tpm_metrics;
-static volatile int hup = 0, term = 0;
-extern char *optarg;
 
-static void
-tcsd_shutdown(void)
+void
+tcsd_shutdown()
 {
 	/* order is important here:
 	 * allow all threads to complete their current request */
@@ -57,27 +54,44 @@
 	EVENT_LOG_final();
 }
 
-static void
-tcsd_signal_term(int signal)
+void
+tcsd_signal_int(int signal)
 {
-	term = 1;
+	switch (signal) {
+		case SIGINT:
+			LogInfo("Caught SIGINT. Cleaning up and exiting.");
+			break;
+		case SIGHUP:
+			LogInfo("Caught SIGHUP. Cleaning up and exiting.");
+			break;
+		default:
+			LogError("Caught signal %d (which I didn't register for!)."
+					" Ignoring.", signal);
+			break;
+	}
+	tcsd_shutdown();
+	exit(signal);
 }
 
 void
-tcsd_signal_hup(int signal)
+tcsd_signal_chld(int signal)
 {
-	hup = 1;
+	/* kill zombies */
+	wait3(NULL, WNOHANG, NULL);
 }
 
-static TSS_RESULT
-signals_init(void)
+TSS_RESULT
+signals_init()
 {
 	int rc;
 	sigset_t sigmask;
-	struct sigaction sa;
 
 	sigemptyset(&sigmask);
-	if ((rc = sigaddset(&sigmask, SIGTERM))) {
+	if ((rc = sigaddset(&sigmask, SIGCHLD))) {
+		LogError("sigaddset: %s", strerror(errno));
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
+	if ((rc = sigaddset(&sigmask, SIGINT))) {
 		LogError("sigaddset: %s", strerror(errno));
 		return TCSERR(TSS_E_INTERNAL_ERROR);
 	}
@@ -91,25 +105,30 @@
 		return TCSERR(TSS_E_INTERNAL_ERROR);
 	}
 
-	sa.sa_flags = 0;
-	sigemptyset(&sa.sa_mask);
-	sa.sa_handler = tcsd_signal_term;
-	if ((rc = sigaction(SIGTERM, &sa, NULL))) {
-		LogError("signal SIGTERM not registered: %s", strerror(errno));
+	tcsd_sa_int.sa_handler = tcsd_signal_int;
+	tcsd_sa_chld.sa_handler = tcsd_signal_chld;
+	tcsd_sa_chld.sa_flags = SA_RESTART;
+
+	if ((rc = sigaction(SIGINT, &tcsd_sa_int, NULL))) {
+		LogError("signal SIGINT not registered: %s", strerror(errno));
 		return TCSERR(TSS_E_INTERNAL_ERROR);
 	}
 
-	sa.sa_handler = tcsd_signal_hup;	
-	if ((rc = sigaction(SIGHUP, &sa, NULL))) {
+	if ((rc = sigaction(SIGHUP, &tcsd_sa_int, NULL))) {
 		LogError("signal SIGHUP not registered: %s", strerror(errno));
 		return TCSERR(TSS_E_INTERNAL_ERROR);
 	}
 
+	if ((rc = sigaction(SIGCHLD, &tcsd_sa_chld, NULL))) {
+		LogError("signal SIGCHLD not registered: %s", strerror(errno));
+		return TCSERR(TSS_E_INTERNAL_ERROR);
+	}
+
 	return TSS_SUCCESS;
 }
 
-static TSS_RESULT
-tcsd_startup(void)
+TSS_RESULT
+tcsd_startup()
 {
 	TSS_RESULT result;
 
@@ -183,7 +202,6 @@
 	return TSS_SUCCESS;
 }
 
-
 void
 usage(void)
 {
@@ -195,19 +213,6 @@
 	fprintf(stderr, "\n");
 }
 
-static TSS_RESULT
-reload_config(void)
-{
-	TSS_RESULT result;
-	hup = 0;
-
-	// FIXME: reload the config - work in progress
-	result = TSS_SUCCESS;
-
-	return result;
-}
-
-
 int
 main(int argc, char **argv)
 {
@@ -216,7 +221,6 @@
 	int sd, newsd, c, option_index = 0;
 	unsigned client_len;
 	char *hostname = NULL;
-	struct passwd *pwd;
 	struct hostent *client_hostent = NULL;
 	struct option long_options[] = {
 		{"help", 0, NULL, 'h'},
@@ -245,6 +249,14 @@
 	if ((result = tcsd_startup()))
 		return (int)result;
 
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
@@ -268,51 +280,20 @@
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
+		LogDebug("accepted socket %i", newsd);
 		if (newsd < 0) {
-			if (errno == EINTR) {
-				if (term)
-					break;
-				else if (hup) {
-					if (reload_config() != TSS_SUCCESS)
-						LogError("Failed reloading config");
-				}
-				continue;
-			} else {
-				LogError("Failed accept: %s", strerror(errno));
-				continue;
-			}
+			LogError("Failed accept: %s", strerror(errno));
+			break;
 		}
-		LogDebug("accepted socket %i", newsd);
 
 		if ((client_hostent = gethostbyaddr((char *) &client_addr.sin_addr,
 						    sizeof(client_addr.sin_addr),
@@ -332,12 +313,8 @@
 
 		tcsd_thread_create(newsd, hostname);
 		hostname = NULL;
-		if (hup) {
-			if (reload_config() != TSS_SUCCESS)
-				LogError("Failed reloading config");
-		}
-	} while (term ==0);
+	} while (1);
 
-	/* To close correctly, we must receive a SIGTERM */
-	return 0;
+	/* To close correctly, we must recieve a SIGHUP */
+	return -1;
 }
