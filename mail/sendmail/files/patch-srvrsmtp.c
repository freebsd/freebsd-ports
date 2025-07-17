--- sendmail/srvrsmtp.c.orig	2024-01-31 06:38:32 UTC
+++ sendmail/srvrsmtp.c
@@ -940,6 +940,9 @@ do								\
 # define SHOWCMDINREPLY(inp) inp
 # define SHOWSHRTCMDINREPLY(inp) shortenstring(inp, MAXSHORTSTR)
 #endif
+#ifdef USE_BLACKLIST
+	int saved_bl_fd;
+#endif
 
 void
 smtp(nullserver, d_flags, e)
@@ -1528,6 +1531,8 @@ smtp(nullserver, d_flags, e)
 			/* check if data is on the socket during the pause */
 			if ((tp = channel_readable(InChannel, msecs)) != NULL)
 			{
+				int fd;
+
 				greetcode = "554";
 				nullserver = "Command rejected";
 				sm_syslog(LOG_INFO, e->e_id,
@@ -1537,6 +1542,8 @@ smtp(nullserver, d_flags, e)
 					  (int) tp->tv_sec +
 						(tp->tv_usec >= 500000 ? 1 : 0)
 					 );
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "pre-greeting traffic");
 			}
 		}
 	}
@@ -1655,6 +1662,10 @@ smtp(nullserver, d_flags, e)
 		SmtpPhase = "server cmd read";
 		sm_setproctitle(true, e, "server %s cmd read", CurSmtpClient);
 
+#ifdef USE_BLACKLIST
+		saved_bl_fd = dup(sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL));
+#endif
+
 		/* handle errors */
 		if (sm_io_error(OutChannel) ||
 		    (p = sfgets(inp, sizeof(inp), InChannel,
@@ -1965,8 +1976,11 @@ smtp(nullserver, d_flags, e)
 #define LOGAUTHFAIL	\
 	do	\
 	{	\
+		int fd;	\
 		SET_AUTH_USER_CONDITIONALLY	\
 		message("535 5.7.0 authentication failed");	\
+		fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);	\
+		BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "AUTH FAIL");	\
 		if (LogLevel >= 9)	\
 			sm_syslog(LOG_WARNING, e->e_id,	\
 				  "AUTH failure (%s): %s (%d) %s%s%.*s, relay=%.100s",	\
@@ -2065,6 +2079,13 @@ smtp(nullserver, d_flags, e)
 			  case CMDEHLO:
 			  case CMDNOOP:
 			  case CMDRSET:
+				if (lognullconnection)
+				{
+					 int fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+					 BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, nullserver);
+				}
+				/* FALLTHROUGH */
+
 			  case CMDERROR:
 				/* process normally */
 				break;
@@ -2092,6 +2113,11 @@ smtp(nullserver, d_flags, e)
 #endif /* MAXBADCOMMANDS > 0 */
 				if (nullserver != NULL)
 				{
+					if (lognullconnection)
+					{
+						 int fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+						 BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, nullserver);
+					}
 					if (ISSMTPREPLY(nullserver))
 					{
 						/* Can't use ("%s", ...) due to usrerr() requirements */
@@ -2116,6 +2142,9 @@ smtp(nullserver, d_flags, e)
 			DELAY_CONN("AUTH");
 			if (!sasl_ok || n_mechs <= 0)
 			{
+				int fd;
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "AUTH LOGIN FAIL");
 				message("503 5.3.3 AUTH not available");
 				break;
 			}
@@ -3841,10 +3870,17 @@ smtp(nullserver, d_flags, e)
 				**  timeouts for the same connection.
 				*/
 
+#ifdef USE_BLACKLIST
+				/* no immediate BLACKLIST_ABUSIVE_BEHAVIOR */
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, saved_bl_fd, "no command issued");
+#endif
 				sm_syslog(LOG_INFO, e->e_id,
 					  "%s did not issue MAIL/EXPN/VRFY/ETRN during connection to %s",
 					  CurSmtpClient, d);
 			}
+#ifdef USE_BLACKLIST
+			close(saved_bl_fd);
+#endif
 			if (tTd(93, 100))
 			{
 				/* return to handle next connection */
@@ -3926,7 +3962,10 @@ smtp(nullserver, d_flags, e)
 #if MAXBADCOMMANDS > 0
 			if (++n_badcmds > MAXBADCOMMANDS)
 			{
+				int fd;
   stopattack:
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_ABUSIVE_BEHAVIOR, fd, "too many bad commands");
 				message("421 4.7.0 %s Too many bad commands; closing connection",
 					MyHostName);
 
@@ -3980,6 +4019,9 @@ smtp(nullserver, d_flags, e)
 		}
 #if SASL
 		}
+#endif
+#ifdef USE_BLACKLIST
+		close(saved_bl_fd);
 #endif
 	    }
 	    SM_EXCEPT(exc, "[!F]*")
