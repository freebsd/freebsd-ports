--- server/main.c.orig	Thu Nov 17 19:15:19 1994
+++ server/main.c	Mon Nov  4 05:34:17 2002
@@ -35,8 +35,10 @@
 #endif
 
 #ifdef SETPROCTITLE
+#ifndef HAVE_PROCTITLE
 char	**Argv = NULL;		/* pointer to argument vector */
 char	*LastArgv = NULL;	/* end of argv */
+#endif
 #endif /* SETPROCTITLE */
 
 int
@@ -81,6 +83,22 @@
 
 #ifndef EXCELAN
 	sockt = get_socket();		/* should be fd 4 or 5 */
+	if ( getuid() == 0 ) {  /* Running as root */
+
+		if (setgid((gid_t) NEWS_GID) == -1) {
+#ifdef SYSLOG
+			syslog(LOG_ERR, "setgid: %m");
+#endif
+			exit(1);
+		}
+
+		if (setuid((uid_t) NEWS_UID) == -1) {
+#ifdef SYSLOG
+			syslog(LOG_ERR, "setuid: %m");
+#endif
+			exit(1);
+		}
+	}
 #ifdef USG
 	(void) signal(SIGCLD, SIG_IGN);
 #else /* !USG */
@@ -101,6 +119,7 @@
 #endif /* EXCELAN */
 
 #ifdef SETPROCTITLE
+#ifndef HAVE_PROCTITLE
 	/*
 	 *  Save start and extent of argv for setproctitle.
 	 */
@@ -113,6 +132,7 @@
 		envp++;
 	LastArgv = envp[-1] + strlen(envp[-1]);
 #endif /*SDD*/
+#endif
 #endif /* SETPROCTITLE */
 #if defined(LOAD) && defined(SETPROCTITLE)
 	/* If LOAD and SETPROCTITLE, display load before first accept() */
@@ -243,6 +263,7 @@
 	}
 #endif /* LOAD */
 #ifdef SETPROCTITLE
+#ifndef HAVE_PROCTITLE
 	/*
 	 *  Save start and extent of argv for setproctitle.
 	 */
@@ -255,6 +276,7 @@
 		envp++;
 	LastArgv = envp[-1] + strlen(envp[-1]);
 #endif /*SDD*/
+#endif
 #endif /* SETPROCTITLE */
 
 #ifdef USG
@@ -271,6 +293,7 @@
  * stolen from sendmail
  */
 #ifdef SETPROCTITLE
+#ifndef HAVE_PROCTITLE
 #if defined(sun) || defined(hpux)
 /*VARARGS*/
 void
@@ -330,4 +353,5 @@
 		*p++ = ' ';
 }
 #endif /* hpux */
+#endif
 #endif /* SETPROCTITLE */
