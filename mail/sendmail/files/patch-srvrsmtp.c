--- sendmail/srvrsmtp.c.orig	2015-03-18 07:47:12.000000000 -0400
+++ sendmail/srvrsmtp.c	2016-06-12 18:36:01.372172000 -0400
@@ -832,6 +832,9 @@
 	int n_badrcpts_adj;
 #endif /* _FFR_BADRCPT_SHUTDOWN */
 
+#ifdef USE_BLACKLIST
+	int fd;
+#endif
 	SevenBitInput_Saved = SevenBitInput;
 	smtp.sm_nrcpts = 0;
 #if MILTER
@@ -1328,6 +1331,9 @@
 					  (int) tp.tv_sec +
 						(tp.tv_usec >= 500000 ? 1 : 0)
 					 );
+#ifdef USE_BLACKLIST
+				blacklist_notify(1, fd, "pre-greeting traffic");
+#endif
 			}
 		}
 	}
@@ -1723,6 +1729,10 @@
 			{
 				/* not SASL_OK or SASL_CONT */
 				message("535 5.7.0 authentication failed");
+#ifdef USE_BLACKLIST
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				blacklist_notify(1, fd, "AUTH FAIL");
+#endif
 				if (LogLevel > 9)
 					sm_syslog(LOG_WARNING, e->e_id,
 						  "AUTH failure (%s): %s (%d) %s, relay=%.100s",
@@ -3524,6 +3534,10 @@
 			if (++n_badcmds > MAXBADCOMMANDS)
 			{
   stopattack:
+#ifdef USE_BLACKLIST
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				blacklist_notify(1, fd, "too many bad commands");
+#endif
 				message("421 4.7.0 %s Too many bad commands; closing connection",
 					MyHostName);
 
