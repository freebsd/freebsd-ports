--- rshd/rshd.c.orig	2026-08-13 18:15:38 UTC
+++ rshd/rshd.c
@@ -88,8 +88,8 @@ __FBSDID("$FreeBSD: head/libexec/rshd/rshd.c 320406 20
 #include <security/openpam.h>
 #include <sys/wait.h>
 
-#ifdef USE_BLOCKLIST
-#include <blocklist.h>
+#ifdef USE_BLACKLIST
+#include <blacklist.h>
 #endif
 
 static struct pam_conv pamc = { openpam_nullconv, NULL };
@@ -256,8 +256,8 @@ doit(struct sockaddr *fromp)
 		    "connection from %s on illegal port %u",
 		    numericname,
 		    srcport);
-#ifdef USE_BLOCKLIST
-		blocklist(1, STDIN_FILENO, "illegal port");
+#ifdef USE_BLACKLIST
+		blacklist(1, STDIN_FILENO, "illegal port");
 #endif
 		exit(1);
 	}
@@ -292,8 +292,8 @@ doit(struct sockaddr *fromp)
 			    "2nd socket from %s on unreserved port %u",
 			    numericname,
 			    port);
-#ifdef USE_BLOCKLIST
-			blocklist(1, STDIN_FILENO, "unreserved port");
+#ifdef USE_BLACKLIST
+			blacklist(1, STDIN_FILENO, "unreserved port");
 #endif
 			exit(1);
 		}
@@ -319,8 +319,8 @@ doit(struct sockaddr *fromp)
 	if (pam_err != PAM_SUCCESS) {
 		syslog(LOG_ERR|LOG_AUTH, "pam_start(): %s",
 		    pam_strerror(pamh, pam_err));
-#ifdef USE_BLOCKLIST
-		blocklist(1, STDIN_FILENO, "login incorrect");
+#ifdef USE_BLACKLIST
+		blacklist(1, STDIN_FILENO, "login incorrect");
 #endif
 		rshd_errx(1, "Login incorrect.");
 	}
@@ -329,8 +329,8 @@ doit(struct sockaddr *fromp)
 	    (pam_err = pam_set_item(pamh, PAM_RHOST, rhost)) != PAM_SUCCESS) {
 		syslog(LOG_ERR|LOG_AUTH, "pam_set_item(): %s",
 		    pam_strerror(pamh, pam_err));
-#ifdef USE_BLOCKLIST
-		blocklist(1, STDIN_FILENO, "login incorrect");
+#ifdef USE_BLACKLIST
+		blacklist(1, STDIN_FILENO, "login incorrect");
 #endif
 		rshd_errx(1, "Login incorrect.");
 	}
@@ -348,8 +348,8 @@ doit(struct sockaddr *fromp)
 		syslog(LOG_INFO|LOG_AUTH,
 		    "%s@%s as %s: permission denied (%s). cmd='%.80s'",
 		    ruser, rhost, luser, pam_strerror(pamh, pam_err), cmdbuf);
-#ifdef USE_BLOCKLIST
-		blocklist(1, STDIN_FILENO, "permission denied");
+#ifdef USE_BLACKLIST
+		blacklist(1, STDIN_FILENO, "permission denied");
 #endif
 		rshd_errx(1, "Login incorrect.");
 	}
@@ -360,8 +360,8 @@ doit(struct sockaddr *fromp)
 		syslog(LOG_INFO|LOG_AUTH,
 		    "%s@%s as %s: unknown login. cmd='%.80s'",
 		    ruser, rhost, luser, cmdbuf);
-#ifdef USE_BLOCKLIST
-		blocklist(1, STDIN_FILENO, "unknown login");
+#ifdef USE_BLACKLIST
+		blacklist(1, STDIN_FILENO, "unknown login");
 #endif
 		if (errorstr == NULL)
 			errorstr = "Login incorrect.";
@@ -395,8 +395,8 @@ doit(struct sockaddr *fromp)
 			    "%s@%s as %s: permission denied (%s). cmd='%.80s'",
 			    ruser, rhost, luser, __rcmd_errstr,
 			    cmdbuf);
-#ifdef USE_BLOCKLIST
-			blocklist(1, STDIN_FILENO, "permission denied");
+#ifdef USE_BLACKLIST
+			blacklist(1, STDIN_FILENO, "permission denied");
 #endif
 			rshd_errx(1, "Login incorrect.");
 		}
@@ -493,8 +493,8 @@ doit(struct sockaddr *fromp)
 		}
 	}
 
-#ifdef USE_BLOCKLIST
-	blocklist(0, STDIN_FILENO, "success");
+#ifdef USE_BLACKLIST
+	blacklist(0, STDIN_FILENO, "success");
 #endif
 	closefrom(3);
 	if (setsid() == -1)
@@ -562,8 +562,8 @@ getstr(char *buf, int cnt, const char *error)
 			exit(1);
 		*buf++ = c;
 		if (--cnt == 0) {
-#ifdef USE_BLOCKLIST
-			blocklist(1, STDIN_FILENO, "buffer overflow");
+#ifdef USE_BLACKLIST
+			blacklist(1, STDIN_FILENO, "buffer overflow");
 #endif
 			rshd_errx(1, "%s too long", error);
 		}
