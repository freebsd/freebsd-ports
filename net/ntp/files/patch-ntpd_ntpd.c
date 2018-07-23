--- ntpd/ntpd.c.orig	2018-02-27 15:15:48 UTC
+++ ntpd/ntpd.c
@@ -123,6 +123,9 @@
 #if defined(HAVE_PRIV_H) && defined(HAVE_SOLARIS_PRIVS)
 # include <priv.h>
 #endif /* HAVE_PRIV_H */
+#if defined(HAVE_TRUSTEDBSD_MAC)
+# include <sys/mac.h>
+#endif /* HAVE_TRUSTEDBSD_MAC */
 #endif /* HAVE_DROPROOT */
 
 #if defined (LIBSECCOMP) && (KERN_SECCOMP)
@@ -634,7 +637,12 @@ ntpdmain(
 	/* MPE lacks the concept of root */
 # if defined(HAVE_GETUID) && !defined(MPE)
 	uid = getuid();
-	if (uid && !HAVE_OPT( SAVECONFIGQUIT )) {
+	if (uid && !HAVE_OPT( SAVECONFIGQUIT )
+#  if defined(HAVE_TRUSTEDBSD_MAC)
+	    /* We can run as non-root if the mac_ntpd policy is enabled. */
+	    && mac_is_present("ntpd") != 1
+#  endif
+	    ) {
 		msyslog_term = TRUE;
 		msyslog(LOG_ERR,
 			"must be run as root, not uid %ld", (long)uid);
@@ -1082,7 +1090,17 @@ getgroup:
 			exit (-1);
 		}
 
-#  if !defined(HAVE_LINUX_CAPABILITIES) && !defined(HAVE_SOLARIS_PRIVS)
+#  if defined(HAVE_TRUSTEDBSD_MAC)
+		/*
+		 * To manipulate system time and (re-)bind to NTP_PORT as needed
+		 * following interface changes, we must either run as uid 0 or
+		 * the mac_ntpd policy module must be enabled.
+		 */
+		if (sw_uid != 0 && mac_is_present("ntpd") != 1) {
+			msyslog(LOG_ERR, "Need MAC 'ntpd' policy enabled to drop root privileges");
+			exit (-1);
+		}
+#  elif !defined(HAVE_LINUX_CAPABILITIES) && !defined(HAVE_SOLARIS_PRIVS)
 		/*
 		 * for now assume that the privilege to bind to privileged ports
 		 * is associated with running with uid 0 - should be refined on
