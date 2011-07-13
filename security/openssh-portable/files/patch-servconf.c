--- servconf.c.orig	2009-01-27 23:31:23.000000000 -0600
+++ servconf.c	2010-01-14 02:10:46.036137657 -0600
@@ -135,7 +135,7 @@
 {
 	/* Portable-specific options */
 	if (options->use_pam == -1)
-		options->use_pam = 0;
+		options->use_pam = 1;
 
 	/* Standard Options */
 	if (options->protocol == SSH_PROTO_UNKNOWN)
@@ -165,7 +165,7 @@
 	if (options->key_regeneration_time == -1)
 		options->key_regeneration_time = 3600;
 	if (options->permit_root_login == PERMIT_NOT_SET)
-		options->permit_root_login = PERMIT_YES;
+		options->permit_root_login = PERMIT_NO;
 	if (options->ignore_rhosts == -1)
 		options->ignore_rhosts = 1;
 	if (options->ignore_user_known_hosts == -1)
@@ -175,7 +175,7 @@
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -213,7 +213,11 @@
 	if (options->gss_cleanup_creds == -1)
 		options->gss_cleanup_creds = 1;
 	if (options->password_authentication == -1)
+#ifdef USE_PAM
+		options->password_authentication = 0;
+#else
 		options->password_authentication = 1;
+#endif
 	if (options->kbd_interactive_authentication == -1)
 		options->kbd_interactive_authentication = 0;
 	if (options->challenge_response_authentication == -1)
@@ -284,6 +288,7 @@
 	sUsePAM,
 	/* Standard Options */
 	sPort, sHostKeyFile, sServerKeyBits, sLoginGraceTime, sKeyRegenerationTime,
+	sVersionAddendum,
 	sPermitRootLogin, sLogFacility, sLogLevel,
 	sRhostsRSAAuthentication, sRSAAuthentication,
 	sKerberosAuthentication, sKerberosOrLocalPasswd, sKerberosTicketCleanup,
@@ -328,6 +333,7 @@
 	{ "pamauthenticationviakbdint", sDeprecated, SSHCFG_GLOBAL },
 	/* Standard Options */
 	{ "port", sPort, SSHCFG_GLOBAL },
+	{ "versionaddendum", sVersionAddendum, SSHCFG_GLOBAL },
 	{ "hostkey", sHostKeyFile, SSHCFG_GLOBAL },
 	{ "hostdsakey", sHostKeyFile, SSHCFG_GLOBAL },		/* alias */
 	{ "pidfile", sPidFile, SSHCFG_GLOBAL },
@@ -1294,6 +1300,13 @@
 			*charptr = xstrdup(arg);
 		break;
 
+	case sVersionAddendum:
+                ssh_version_set_addendum(strtok(cp, "\n"));
+                do {
+                        arg = strdelim(&cp);
+                } while (arg != NULL && *arg != '\0');
+		break;
+
 	case sDeprecated:
 		logit("%s line %d: Deprecated option %s",
 		    filename, linenum, arg);
