--- helper.c	2007/08/10 18:37:27	1.24
+++ helper.c	2008/03/08 18:57:48	1.25
@@ -26,6 +26,11 @@
 #endif
 #endif
 
+#ifdef RSYNC_COMPAT
+#define RSYNC_ARG_SERVER 0x01
+#define RSYNC_ARG_EXECUTE 0x02
+#endif
+
 #define MAX(x,y)	( ( x > y ) ? x : y )
 #define MIN(x,y)	( ( x < y ) ? x : y )
 
@@ -164,6 +169,13 @@
 	int			ch;
 	int			ac=0;
 	int			longopt_index = 0;
+#ifdef RSYNC_COMPAT
+	/* 
+	 * bitwise flag: 0x01 = server, 0x02 = -e.
+	 * Thus 0x03 is allowed and 0x01 is allowed, but 0x02 is not allowed
+	 */
+	int			rsync_flags = 0; 
+#endif /* RSYNC_COMPAT */
 
 	while (cmdarg != NULL)
 	{
@@ -182,7 +194,7 @@
 			 */
 			if (1 == cmdarg->getoptflag)
 			{
-				debug(LOG_DEBUG, "Using getopt processing for cmd %s\n (%s)", cmdarg->name, logstamp());
+				debug(LOG_DEBUG, "Using getopt processing for cmd%s\n (%s)", cmdarg->name, logstamp());
 				/*	
 				 *	first count the arguments in the vector
 				 */
@@ -207,7 +219,7 @@
 				 *	otherwise, try a glibc-style reset of the global getopt vars
 				 */
 				optind=0;
-#endif
+#endif /* HAVE_OPTRESET */
 				/*
 				 *	tell getopt to only be strict if the 'opts' is well defined
 				 */
@@ -216,6 +228,18 @@
 					
 					debug(LOG_DEBUG, "getopt processing returned '%c' (%s)", ch, logstamp());
 					
+#ifdef RSYNC_COMPAT
+					if (exact_match(cmdarg->name, PROG_RSYNC) && (ch == 's' || ch == 'e')) {
+						if (ch == 's')
+							rsync_flags |= RSYNC_ARG_SERVER;
+						else
+							/* -e */
+							rsync_flags |= RSYNC_ARG_EXECUTE;
+						debug(LOG_DEBUG, "rsync_flags are now set to: %0x", rsync_flags);
+					}
+					else
+#endif /* RSYNC_COMPAT */
+
 					/* if the character is found in badarg, then it's not a permitted option */
 					if (cmdarg->badarg != NULL && (strchr(cmdarg->badarg, ch) != NULL))
 					{
@@ -230,14 +254,23 @@
 						return 1;
 					}
 				}
-#elif
+#ifdef RSYNC_COMPAT
+				/* it's not safe if the execute flag was set and server was not set */
+				if ((rsync_flags & RSYNC_ARG_EXECUTE) != 0 && (rsync_flags & RSYNC_ARG_SERVER) == 0) {
+						syslog(LOG_ERR, "option 'e' is not allowed unless '--server' is also set with cmd %s (%s)", 
+							PROG_RSYNC, logstamp());
+						return 1;
+				}
+#endif /* RSYNC_COMPAT */
+
+#elif /* HAVE_GETOPT */
 				/*
 				 * make sure that processing doesn't continue if we can't validate a rsync check
 				 * and if the getopt flag is set.
 				 */
 				syslog(LOG_ERR, "a getopt() argument check could not be performed for %s, recompile scponly without support for %s or rebuild scponly with getopt", av[0], av[0]);
 				return 1;
-#endif
+#endif /* HAVE_GETOPT */
 			}
 			else
 			/*
