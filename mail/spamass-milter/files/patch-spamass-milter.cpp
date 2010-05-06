--- spamass-milter.cpp.orig	2010-05-06 11:24:40.000000000 +0200
+++ spamass-milter.cpp	2010-05-06 11:25:01.000000000 +0200
@@ -171,10 +171,6 @@
 bool flag_expand = false;	/* alias/virtusertable expansion */
 bool warnedmacro = false;	/* have we logged that we couldn't fetch a macro? */
 
-#if defined(__FreeBSD__) /* popen bug - see PR bin/50770 */
-static pthread_mutex_t popen_mutex = PTHREAD_MUTEX_INITIALIZER;
-#endif
-
 // {{{ main()
 
 int
@@ -461,59 +457,24 @@
 			   send another copy.  The milter API will not let you send the
 			   message AND return a failure code to the sender, so this is
 			   the only way to do it. */
-#if defined(__FreeBSD__)
-			int rv;
-#endif
-			
-#if defined(HAVE_ASPRINTF)
-			char *buf;
-#else
-			char buf[1024];
-#endif
-			char *fmt="%s \"%s\"";
+			char *popen_argv[3];
 			FILE *p;
 
-#if defined(HAVE_ASPRINTF)
-			asprintf(&buf, fmt, SENDMAIL, spambucket);
-#else
-#if defined(HAVE_SNPRINTF)
-			snprintf(buf, sizeof(buf)-1, fmt, SENDMAIL, spambucket);
-#else
-			/* XXX possible buffer overflow here */
-			sprintf(buf, fmt, SENDMAIL, spambucket);
-#endif
-#endif
-
-			debug(D_COPY, "calling %s", buf);
-#if defined(__FreeBSD__) /* popen bug - see PR bin/50770 */
-			rv = pthread_mutex_lock(&popen_mutex);
-			if (rv)
-			{
-				debug(D_ALWAYS, "Could not lock popen mutex: %s", strerror(rv));
-				abort();
-			}		
-#endif
-			p = popen(buf, "w");
+			popen_argv[0] = SENDMAIL;
+			popen_argv[1] = spambucket;
+			popen_argv[2] = NULL;
+			
+			debug(D_COPY, "calling %s %s", SENDMAIL, spambucket);
+			p = popenv(popen_argv, "w");
 			if (!p)
 			{
-				debug(D_COPY, "popen failed(%s).  Will not send a copy to spambucket", strerror(errno));
+				debug(D_COPY, "popenv failed(%s).  Will not send a copy to spambucket", strerror(errno));
 			} else
 			{
 				// Send message provided by SpamAssassin
 				fwrite(assassin->d().c_str(), assassin->d().size(), 1, p);
-				pclose(p); p = NULL;
+				fclose(p); p = NULL;
 			}
-#if defined(__FreeBSD__)
-			rv = pthread_mutex_unlock(&popen_mutex);
-			if (rv)
-			{
-				debug(D_ALWAYS, "Could not unlock popen mutex: %s", strerror(rv));
-				abort();
-			}		
-#endif
-#if defined(HAVE_ASPRINTF)
-			free(buf);
-#endif 
 		}
 		return SMFIS_REJECT;
 	}
@@ -842,30 +803,19 @@
 		/* open a pipe to sendmail so we can do address expansion */
 
 		char buf[1024];
-		char *fmt="%s -bv \"%s\" 2>&1";
-
-#if defined(HAVE_SNPRINTF)
-		snprintf(buf, sizeof(buf)-1, fmt, SENDMAIL, envrcpt[0]);
-#else
-		/* XXX possible buffer overflow here */
-		sprintf(buf, fmt, SENDMAIL, envrcpt[0]);
-#endif
+		char *popen_argv[4];
+		
+		popen_argv[0] = SENDMAIL;
+		popen_argv[1] = "-bv";
+		popen_argv[2] = envrcpt[0];
+		popen_argv[3] = NULL;
 
-		debug(D_RCPT, "calling %s", buf);
+		debug(D_RCPT, "calling %s -bv %s", SENDMAIL, envrcpt[0]);
 
-#if defined(__FreeBSD__) /* popen bug - see PR bin/50770 */
-		rv = pthread_mutex_lock(&popen_mutex);
-		if (rv)
-		{
-			debug(D_ALWAYS, "Could not lock popen mutex: %s", strerror(rv));
-			abort();
-		}		
-#endif
-
-		p = popen(buf, "r");
+		p = popenv(popen_argv, "r");
 		if (!p)
 		{
-			debug(D_RCPT, "popen failed(%s).  Will not expand aliases", strerror(errno));
+			debug(D_RCPT, "popenv failed(%s).  Will not expand aliases", strerror(errno));
 			assassin->expandedrcpt.push_back(envrcpt[0]);
 		} else
 		{
@@ -890,16 +840,8 @@
 					assassin->expandedrcpt.push_back(p+7);
 				}
 			}
-			pclose(p); p = NULL;
+			fclose(p); p = NULL;
 		}
-#if defined(__FreeBSD__)
-		rv = pthread_mutex_unlock(&popen_mutex);
-		if (rv)
-		{
-			debug(D_ALWAYS, "Could not unlock popen mutex: %s", strerror(rv));
-			abort();
-		}		
-#endif
 	} else
 	{
 		assassin->expandedrcpt.push_back(envrcpt[0]);
@@ -2157,5 +2099,71 @@
 	warnedmacro = true;
 }
 
+/*
+   untrusted-argument-safe popen function - only supports "r" and "w" modes
+   for simplicity, and always reads stdout and stderr in "r" mode.  Call
+   fclose to close the FILE.
+*/
+FILE *popenv(char *const argv[], const char *type)
+{
+	FILE *iop;
+	int pdes[2];
+	int save_errno;
+	if ((*type != 'r' && *type != 'w') || type[1])
+	{
+		errno = EINVAL;
+		return (NULL);
+	}
+	if (pipe(pdes) < 0)
+		return (NULL);
+	switch (fork()) {
+	
+	case -1:			/* Error. */
+		save_errno = errno;
+		(void)close(pdes[0]);
+		(void)close(pdes[1]);
+		errno = save_errno;
+		return (NULL);
+		/* NOTREACHED */
+	case 0:				/* Child. */
+		if (*type == 'r') {
+			/*
+			 * The dup2() to STDIN_FILENO is repeated to avoid
+			 * writing to pdes[1], which might corrupt the
+			 * parent's copy.  This isn't good enough in
+			 * general, since the exit() is no return, so
+			 * the compiler is free to corrupt all the local
+			 * variables.
+			 */
+			(void)close(pdes[0]);
+			(void)dup2(pdes[1], STDOUT_FILENO);
+			(void)dup2(pdes[1], STDERR_FILENO);
+			if (pdes[1] != STDOUT_FILENO && pdes[1] != STDERR_FILENO) {
+				(void)close(pdes[1]);
+			} 
+		} else {
+			if (pdes[0] != STDIN_FILENO) {
+				(void)dup2(pdes[0], STDIN_FILENO);
+				(void)close(pdes[0]);
+			}
+			(void)close(pdes[1]);
+		}
+		execv(argv[0], argv);
+		exit(127);
+		/* NOTREACHED */
+	}
+
+	/* Parent; assume fdopen can't fail. */
+	if (*type == 'r') {
+		iop = fdopen(pdes[0], type);
+		(void)close(pdes[1]);
+	} else {
+		iop = fdopen(pdes[1], type);
+		(void)close(pdes[0]);
+	}
+
+	return (iop);
+}
+
 // }}}
 // vim6:ai:noexpandtab
