--- rlogind/rlogind.c.orig	2026-08-13 18:14:28 UTC
+++ rlogind/rlogind.c
@@ -83,8 +83,8 @@ __FBSDID("$FreeBSD: head/libexec/rlogind/rlogind.c 301
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#ifdef USE_BLOCKLIST
-#include <blocklist.h>
+#ifdef USE_BLACKLIST
+#include <blacklist.h>
 #endif
 
 #ifndef TIOCPKT_WINDOW
@@ -231,8 +231,8 @@ doit(int f, union sockunion *fromp)
 			/* error check ? */
 			syslog(LOG_NOTICE, "Connection from %s on illegal port",
 			       nameinfo);
-#ifdef USE_BLOCKLIST
-			blocklist(1, STDIN_FILENO, "illegal port");
+#ifdef USE_BLACKLIST
+			blacklist(1, STDIN_FILENO, "illegal port");
 #endif
 			fatal(f, "Permission denied", 0);
 		}
@@ -257,8 +257,8 @@ doit(int f, union sockunion *fromp)
 						"Connection refused from %s with IP option %s",
 						inet_ntoa(fromp->su_sin.sin_addr),
 						c == IPOPT_LSRR ? "LSRR" : "SSRR");
-#ifdef USE_BLOCKLIST
-					blocklist(1, STDIN_FILENO, "source routing present");
+#ifdef USE_BLACKLIST
+					blacklist(1, STDIN_FILENO, "source routing present");
 #endif
 					exit(1);
 				}
@@ -292,13 +292,13 @@ doit(int f, union sockunion *fromp)
 		if (*lusername=='-') {
 			syslog(LOG_ERR, "tried to pass user \"%s\" to login",
 			       lusername);
-#ifdef USE_BLOCKLIST
-			blocklist(1, STDIN_FILENO, "invalid user");
+#ifdef USE_BLACKLIST
+			blacklist(1, STDIN_FILENO, "invalid user");
 #endif
 			fatal(STDERR_FILENO, "invalid user", 0);
 		}
-#ifdef USE_BLOCKLIST
-		blocklist(0, STDIN_FILENO, "success");
+#ifdef USE_BLACKLIST
+		blacklist(0, STDIN_FILENO, "success");
 #endif
 		if (authenticated) {
 			execl(_PATH_LOGIN, "login", "-p",
@@ -519,8 +519,8 @@ getstr(char *buf, int cnt, char *errmsg)
 		if (read(STDIN_FILENO, &c, 1) != 1)
 			exit(1);
 		if (--cnt < 0) {
-#ifdef USE_BLOCKLIST
-			blocklist(1, STDIN_FILENO, "buffer overflow");
+#ifdef USE_BLACKLIST
+			blacklist(1, STDIN_FILENO, "buffer overflow");
 #endif
 			fatal(STDOUT_FILENO, errmsg, 0);
 		}
