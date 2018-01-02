--- sendmail/srvrsmtp.c.orig	2015-03-18 11:47:12 UTC
+++ sendmail/srvrsmtp.c
@@ -1328,6 +1328,7 @@ smtp(nullserver, d_flags, e)
 					  (int) tp.tv_sec +
 						(tp.tv_usec >= 500000 ? 1 : 0)
 					 );
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "pre-greeting traffic");
 			}
 		}
 	}
@@ -1721,8 +1722,11 @@ smtp(nullserver, d_flags, e)
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
@@ -3523,7 +3527,10 @@ doquit:
 #if MAXBADCOMMANDS > 0
 			if (++n_badcmds > MAXBADCOMMANDS)
 			{
+				int fd;
   stopattack:
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_ABUSIVE_BEHAVIOR, fd, "too many bad commands");
 				message("421 4.7.0 %s Too many bad commands; closing connection",
 					MyHostName);
 
