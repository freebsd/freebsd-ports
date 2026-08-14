--- sendmail/srvrsmtp.c.orig	2026-04-20 17:18:50 UTC
+++ sendmail/srvrsmtp.c
@@ -930,6 +930,9 @@ do								\
 # define SHOWCMDINREPLY(inp) inp
 # define SHOWSHRTCMDINREPLY(inp) shortenstring(inp, MAXSHORTSTR)
 #endif
+#ifdef USE_BLOCKLIST
+	int saved_bl_fd;
+#endif
 
 void
 smtp(char *volatile nullserver, BITMAP256 d_flags,
@@ -1521,6 +1524,8 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 			/* check if data is on the socket during the pause */
 			if ((tp = channel_readable(InChannel, msecs)) != NULL)
 			{
+				int fd;
+
 				greetcode = "554";
 				nullserver = "Command rejected";
 				sm_syslog(LOG_INFO, e->e_id,
@@ -1530,6 +1535,8 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 					  (int) tp->tv_sec +
 						(tp->tv_usec >= 500000 ? 1 : 0)
 					 );
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, fd, "pre-greeting traffic");
 			}
 		}
 	}
@@ -1649,6 +1656,10 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 		SmtpPhase = "server cmd read";
 		sm_setproctitle(true, e, "server %s cmd read", CurSmtpClient);
 
+#ifdef USE_BLOCKLIST
+		saved_bl_fd = dup(sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL));
+#endif
+
 		/* handle errors */
 		if (sm_io_error(OutChannel) ||
 		    (p = sfgets(inp, sizeof(inp), InChannel,
@@ -1964,8 +1975,11 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 #define LOGAUTHFAIL	\
 	do	\
 	{	\
+		int fd;	\
 		SET_AUTH_USER_CONDITIONALLY	\
 		message("535 5.7.0 authentication failed");	\
+		fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);	\
+		BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, fd, "AUTH FAIL");	\
 		if (LogLevel >= 9)	\
 			sm_syslog(LOG_WARNING, e->e_id,	\
 				  "AUTH failure (%s): %s (%d) %s%s%.*s, relay=%.100s",	\
@@ -2064,6 +2078,13 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 			  case CMDEHLO:
 			  case CMDNOOP:
 			  case CMDRSET:
+				if (lognullconnection)
+				{
+					 int fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+					 BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, fd, nullserver);
+				}
+				/* FALLTHROUGH */
+
 			  case CMDERROR:
 				/* process normally */
 				break;
@@ -2091,6 +2112,11 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 #endif /* MAXBADCOMMANDS > 0 */
 				if (nullserver != NULL)
 				{
+					if (lognullconnection)
+					{
+						 int fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+						 BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, fd, nullserver);
+					}
 					if (ISSMTPREPLY(nullserver))
 					{
 						/* Can't use ("%s", ...) due to usrerr() requirements */
@@ -2115,6 +2141,9 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 			DELAY_CONN("AUTH");
 			if (!sasl_ok || n_mechs <= 0)
 			{
+				int fd;
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, fd, "AUTH LOGIN FAIL");
 				message("503 5.3.3 AUTH not available");
 				break;
 			}
@@ -3904,10 +3933,17 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 				**  timeouts for the same connection.
 				*/
 
+#ifdef USE_BLOCKLIST
+				/* no immediate BLOCKLIST_ABUSIVE_BEHAVIOR */
+				BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, saved_bl_fd, "no command issued");
+#endif
 				sm_syslog(LOG_INFO, e->e_id,
 					  "%s did not issue MAIL/EXPN/VRFY/ETRN during connection to %s",
 					  CurSmtpClient, d);
 			}
+#ifdef USE_BLOCKLIST
+			close(saved_bl_fd);
+#endif
 			if (tTd(93, 100))
 			{
 				/* return to handle next connection */
@@ -3989,7 +4025,10 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 #if MAXBADCOMMANDS > 0
 			if (++n_badcmds > MAXBADCOMMANDS)
 			{
+				int fd;
   stopattack:
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLOCKLIST_NOTIFY(BLOCKLIST_ABUSIVE_BEHAVIOR, fd, "too many bad commands");
 				message("421 4.7.0 %s Too many bad commands; closing connection",
 					MyHostName);
 
@@ -4043,6 +4082,9 @@ smtp(char *volatile nullserver, BITMAP256 d_flags,
 		}
 #if SASL
 		}
+#endif
+#ifdef USE_BLOCKLIST
+		close(saved_bl_fd);
 #endif
 	    }
 	    SM_EXCEPT(exc, "[!F]*")
