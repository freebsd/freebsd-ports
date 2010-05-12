--- spamass-milter.cpp.orig	2006-03-23 22:41:36.000000000 +0100
+++ spamass-milter.cpp	2010-05-12 12:05:02.000000000 +0200
@@ -465,26 +465,11 @@
 			int rv;
 #endif
 			
-#if defined(HAVE_ASPRINTF)
-			char *buf;
-#else
-			char buf[1024];
-#endif
-			char *fmt="%s \"%s\"";
 			FILE *p;
+			char sendmail_prog[] = SENDMAIL;
+			char *const popen_argv[] = { sendmail_prog, spambucket, NULL };
+			pid_t pid;
 
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
 #if defined(__FreeBSD__) /* popen bug - see PR bin/50770 */
 			rv = pthread_mutex_lock(&popen_mutex);
 			if (rv)
@@ -493,15 +478,17 @@
 				abort();
 			}		
 #endif
-			p = popen(buf, "w");
+			debug(D_COPY, "calling %s %s", SENDMAIL, spambucket);
+			p = popenv(popen_argv, "w", &pid);
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
+				waitpid(pid, NULL, 0);
 			}
 #if defined(__FreeBSD__)
 			rv = pthread_mutex_unlock(&popen_mutex);
@@ -511,9 +498,6 @@
 				abort();
 			}		
 #endif
-#if defined(HAVE_ASPRINTF)
-			free(buf);
-#endif 
 		}
 		return SMFIS_REJECT;
 	}
@@ -842,16 +826,12 @@
 		/* open a pipe to sendmail so we can do address expansion */
 
 		char buf[1024];
-		char *fmt="%s -bv \"%s\" 2>&1";
+		char sendmail_prog[] = SENDMAIL;
+		char sendmail_mode[] = "-bv";
+		char * const popen_argv[] = { sendmail_prog, sendmail_mode, envrcpt[0], NULL };
+		pid_t pid;
 
-#if defined(HAVE_SNPRINTF)
-		snprintf(buf, sizeof(buf)-1, fmt, SENDMAIL, envrcpt[0]);
-#else
-		/* XXX possible buffer overflow here */
-		sprintf(buf, fmt, SENDMAIL, envrcpt[0]);
-#endif
-
-		debug(D_RCPT, "calling %s", buf);
+		debug(D_RCPT, "calling %s -bv %s", SENDMAIL, envrcpt[0]);
 
 #if defined(__FreeBSD__) /* popen bug - see PR bin/50770 */
 		rv = pthread_mutex_lock(&popen_mutex);
@@ -862,10 +842,10 @@
 		}		
 #endif
 
-		p = popen(buf, "r");
+		p = popenv(popen_argv, "r", &pid);
 		if (!p)
 		{
-			debug(D_RCPT, "popen failed(%s).  Will not expand aliases", strerror(errno));
+			debug(D_RCPT, "popenv failed(%s).  Will not expand aliases", strerror(errno));
 			assassin->expandedrcpt.push_back(envrcpt[0]);
 		} else
 		{
@@ -890,7 +870,8 @@
 					assassin->expandedrcpt.push_back(p+7);
 				}
 			}
-			pclose(p); p = NULL;
+			fclose(p); p = NULL;
+			waitpid(pid, NULL, 0);
 		}
 #if defined(__FreeBSD__)
 		rv = pthread_mutex_unlock(&popen_mutex);
@@ -1002,9 +983,9 @@
 
 		assassin->output((string)
 			"Received: from "+macro_s+" ("+macro__+")\r\n\t"+
-			"by "+macro_j+"("+macro_v+"/"+macro_Z+") with "+macro_r+" id "+macro_i+"\r\n\t"+
+			"by "+macro_j+" ("+macro_v+"/"+macro_Z+") with "+macro_r+" id "+macro_i+";\r\n\t"+
 			macro_b+"\r\n\t"+
-			"(envelope-from "+assassin->from()+"\r\n");
+			"(envelope-from "+assassin->from()+")\r\n");
 
 	} else
 		assassin->output((string)"X-Envelope-To: "+envrcpt[0]+"\r\n");
@@ -2157,5 +2138,72 @@
 	warnedmacro = true;
 }
 
+/*
+   untrusted-argument-safe popen function - only supports "r" and "w" modes
+   for simplicity, and always reads stdout and stderr in "r" mode.  Call
+   fclose to close the FILE, and waitpid to reap the child process (pid).
+*/
+FILE *popenv(char *const argv[], const char *type, pid_t *pid)
+{
+       FILE *iop;
+       int pdes[2];
+       int save_errno;
+
+       if ((*type != 'r' && *type != 'w') || type[1])
+       {
+               errno = EINVAL;
+               return (NULL);
+       }
+       if (pipe(pdes) < 0)
+               return (NULL);
+       switch (*pid = fork()) {
+
+       case -1:                        /* Error. */
+               save_errno = errno;
+               (void)close(pdes[0]);
+               (void)close(pdes[1]);
+               errno = save_errno;
+               return (NULL);
+               /* NOTREACHED */
+       case 0:                         /* Child. */
+               if (*type == 'r') {
+                       /*
+                        * The dup2() to STDIN_FILENO is repeated to avoid
+                        * writing to pdes[1], which might corrupt the
+                        * parent's copy.  This isn't good enough in
+                        * general, since the exit() is no return, so
+                        * the compiler is free to corrupt all the local
+                        * variables.
+                        */
+                       (void)close(pdes[0]);
+                       (void)dup2(pdes[1], STDOUT_FILENO);
+                       (void)dup2(pdes[1], STDERR_FILENO);
+                       if (pdes[1] != STDOUT_FILENO && pdes[1] != STDERR_FILENO) {
+                               (void)close(pdes[1]);
+                       }
+               } else {
+                       if (pdes[0] != STDIN_FILENO) {
+                               (void)dup2(pdes[0], STDIN_FILENO);
+                               (void)close(pdes[0]);
+                       }
+                       (void)close(pdes[1]);
+               }
+               execv(argv[0], argv);
+               exit(127);
+               /* NOTREACHED */
+       }
+
+       /* Parent; assume fdopen can't fail. */
+       if (*type == 'r') {
+               iop = fdopen(pdes[0], type);
+               (void)close(pdes[1]);
+       } else {
+               iop = fdopen(pdes[1], type);
+               (void)close(pdes[0]);
+       }
+
+       return (iop);
+}
+
 // }}}
 // vim6:ai:noexpandtab
