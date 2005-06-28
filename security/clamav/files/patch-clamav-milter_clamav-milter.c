--- clamav-milter/clamav-milter.c.orig	Tue Jun 28 00:20:39 2005
+++ clamav-milter/clamav-milter.c	Tue Jun 28 00:22:33 2005
@@ -1054,9 +1054,11 @@
 
 		if(cfgopt(copt, "LogVerbose")) {
 			logVerbose = 1;
+#if defined(SENDMAIL_VERSION_A) && defined(SENDMAIL_VERSION_B)
 #if	((SENDMAIL_VERSION_A > 8) || ((SENDMAIL_VERSION_A == 8) && (SENDMAIL_VERSION_B >= 13)))
 			smfi_setdbg(6);
 #endif
+#endif
 		}
 		use_syslog = 1;
 
@@ -1573,11 +1575,13 @@
 		return EX_UNAVAILABLE;
 	}
 
+#if defined(SENDMAIL_VERSION_A) && defined(SENDMAIL_VERSION_B)
 #if	((SENDMAIL_VERSION_A > 8) || ((SENDMAIL_VERSION_A == 8) && (SENDMAIL_VERSION_B >= 13)))
 	if(smfi_opensocket(1) == MI_FAILURE) {
 		cli_errmsg("Can't open/create %s\n", port);
 		return EX_CONFIG;
 	}
+#endif
 #endif
 
 	signal(SIGPIPE, SIG_IGN);	/* libmilter probably does this as well */
