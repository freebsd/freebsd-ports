--- scanbuttond.c.orig	Fri Feb 17 00:23:53 2006
+++ scanbuttond.c	Thu Apr  6 00:52:29 2006
@@ -223,8 +223,15 @@
 		exit(EXIT_FAILURE);
 	}
 
+	openlog(NULL, 0, LOG_DAEMON);
+
 	// daemonize
 	if (daemonize) {
+		if (daemon(0, 0) != 0) {
+			syslog(LOG_ERR, "daemon() failed.");
+		}
+	}
+/*
 		pid = fork();
 		if (pid < 0) {
 			printf("Can't fork!\n");
@@ -259,6 +266,7 @@
 		close(STDOUT_FILENO);
 		close(STDERR_FILENO);
 	}
+*/
 
 	// setup the environment
 	char* oldpath = getenv("PATH");
@@ -292,7 +300,7 @@
 	signal(SIGHUP, &sighandler);
 	signal(SIGINT, &sighandler);
 	signal(SIGSEGV, &sighandler);
-	signal(SIGCLD, SIG_IGN);
+	signal(SIGCHLD, SIG_IGN);
 
 	syslog(LOG_INFO, "scanbuttond started");
 
