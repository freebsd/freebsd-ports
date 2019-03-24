--- sendmail/srvrsmtp.c.orig	2015-03-18 11:47:12 UTC
+++ sendmail/srvrsmtp.c
@@ -831,6 +831,9 @@ smtp(nullserver, d_flags, e)
 #if _FFR_BADRCPT_SHUTDOWN
 	int n_badrcpts_adj;
 #endif /* _FFR_BADRCPT_SHUTDOWN */
+#ifdef USE_BLACKLIST
+	int saved_bl_fd;
+#endif
 
 	SevenBitInput_Saved = SevenBitInput;
 	smtp.sm_nrcpts = 0;
@@ -1328,6 +1331,7 @@ smtp(nullserver, d_flags, e)
 					  (int) tp.tv_sec +
 						(tp.tv_usec >= 500000 ? 1 : 0)
 					 );
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "pre-greeting traffic");
 			}
 		}
 	}
@@ -1421,6 +1425,10 @@ smtp(nullserver, d_flags, e)
 		SmtpPhase = "server cmd read";
 		sm_setproctitle(true, e, "server %s cmd read", CurSmtpClient);
 
+#ifdef USE_BLACKLIST
+		saved_bl_fd = dup(sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL));
+#endif
+
 		/* handle errors */
 		if (sm_io_error(OutChannel) ||
 		    (p = sfgets(inp, sizeof(inp), InChannel,
@@ -1721,8 +1729,11 @@ smtp(nullserver, d_flags, e)
 			}
 			else
 			{
+				int fd;
 				/* not SASL_OK or SASL_CONT */
 				message("535 5.7.0 authentication failed");
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "AUTH FAIL");
 				if (LogLevel > 9)
 					sm_syslog(LOG_WARNING, e->e_id,
 						  "AUTH failure (%s): %s (%d) %s, relay=%.100s",
@@ -1867,6 +1878,9 @@ smtp(nullserver, d_flags, e)
 			DELAY_CONN("AUTH");
 			if (!sasl_ok || n_mechs <= 0)
 			{
+				int fd;
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "AUTH LOGIN FAIL");
 				message("503 5.3.3 AUTH not available");
 				break;
 			}
@@ -3462,10 +3476,17 @@ doquit:
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
@@ -3523,7 +3544,10 @@ doquit:
 #if MAXBADCOMMANDS > 0
 			if (++n_badcmds > MAXBADCOMMANDS)
 			{
+				int fd;
   stopattack:
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_ABUSIVE_BEHAVIOR, fd, "too many bad commands");
 				message("421 4.7.0 %s Too many bad commands; closing connection",
 					MyHostName);
 
@@ -3575,6 +3599,9 @@ doquit:
 #if SASL
 		}
 #endif /* SASL */
+#ifdef USE_BLACKLIST
+		close(saved_bl_fd);
+#endif
 	    }
 	    SM_EXCEPT(exc, "[!F]*")
 	    {
