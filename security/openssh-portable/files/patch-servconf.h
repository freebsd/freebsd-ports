Match FreeBSD base defaults.

--- servconf.h.orig	2026-10-10 09:53:32.414646000 -0700
+++ servconf.h	2026-10-10 09:55:49.384828000 -0700
@@ -163,6 +163,12 @@ SSHCONF_NONCONF(timingsecret)
 SSHCONF_CUSTOM(RekeyLimit, rekeylimit, SSHCFG_ALL, SSHCFG_COPY_MATCH) \
 SSHCONF_CUSTOM(PubkeyAuthOptions, pubkey_auth_options, SSHCFG_ALL, SSHCFG_COPY_MATCH) \
 SSHCONF_NONCONF(timingsecret)
+
+#ifdef USE_PAM
+#define SSHCONF_PASSWD_AUTH_DEFAULT 0
+#else
+#define SSHCONF_PASSWD_AUTH_DEFAULT 1
+#endif
 
 #define SSHD_CONFIG_ENTRIES_MAIN \
 SSHCONF_INT(address_family, AddressFamily, SSHCFG_GLOBAL, multistate_addressfamily, AF_UNSPEC, SSHCFG_COPY_NONE) \
@@ -172,7 +178,7 @@ SSHCONF_INT(login_grace_time, LoginGraceTime, SSHCFG_G
 SSHCONF_STRING(pid_file, PidFile, SSHCFG_GLOBAL, SSHCFG_COPY_NONE) \
 SSHCONF_STRING(moduli_file, ModuliFile, SSHCFG_GLOBAL, SSHCFG_COPY_NONE) \
 SSHCONF_INT(login_grace_time, LoginGraceTime, SSHCFG_GLOBAL, NULL, SSHD_DEFAULT_LOGIN_GRACE_TIME, SSHCFG_COPY_NONE) \
-SSHCONF_INT(permit_root_login, PermitRootLogin, SSHCFG_ALL, multistate_permitrootlogin, PERMIT_NO_PASSWD, SSHCFG_COPY_MATCH) \
+SSHCONF_INT(permit_root_login, PermitRootLogin, SSHCFG_ALL, multistate_permitrootlogin, PERMIT_NO, SSHCFG_COPY_MATCH) \
 SSHCONF_INT(ignore_rhosts, IgnoreRhosts, SSHCFG_ALL, multistate_ignore_rhosts, 1, SSHCFG_COPY_MATCH) \
 SSHCONF_INTFLAG(ignore_user_known_hosts, IgnoreUserKnownHosts, SSHCFG_GLOBAL, 0, SSHCFG_COPY_NONE) \
 SSHCONF_INTFLAG(print_motd, PrintMotd, SSHCFG_GLOBAL, 1, SSHCFG_COPY_NONE) \
@@ -195,7 +201,7 @@ SSHCONF_STRING(pubkey_accepted_algos, PubkeyAcceptedAl
 SSHCONF_STRING(ca_sign_algorithms, CASignatureAlgorithms, SSHCFG_ALL, SSHCFG_COPY_MATCH) \
 SSHCONF_INTFLAG(pubkey_authentication, PubkeyAuthentication, SSHCFG_ALL, 1, SSHCFG_COPY_MATCH) \
 SSHCONF_STRING(pubkey_accepted_algos, PubkeyAcceptedAlgorithms, SSHCFG_ALL, SSHCFG_COPY_MATCH) \
-SSHCONF_INTFLAG(password_authentication, PasswordAuthentication, SSHCFG_ALL, 1, SSHCFG_COPY_MATCH) \
+SSHCONF_INTFLAG(password_authentication, PasswordAuthentication, SSHCFG_ALL, SSHCONF_PASSWD_AUTH_DEFAULT, SSHCFG_COPY_MATCH) \
 SSHCONF_INTFLAG(kbd_interactive_authentication, KbdInteractiveAuthentication, SSHCFG_ALL, 1, SSHCFG_COPY_MATCH) \
 SSHCONF_INTFLAG(permit_empty_passwd, PermitEmptyPasswords, SSHCFG_ALL, 0, SSHCFG_COPY_MATCH) \
 SSHCONF_INT(compression, Compression, SSHCFG_GLOBAL, multistate_compression, SSHD_DEFAULT_COMPRESSION, SSHCFG_COPY_NONE) \
@@ -285,7 +291,7 @@ SSHCONF_ALIAS(KeepAlive, TCPKeepAlive, SSHCFG_GLOBAL)
 
 #ifdef USE_PAM
 #define SSHD_CONFIG_ENTRIES_PAM \
-SSHCONF_INTFLAG(use_pam, UsePAM, SSHCFG_GLOBAL, 0, SSHCFG_COPY_NONE) \
+SSHCONF_INTFLAG(use_pam, UsePAM, SSHCFG_GLOBAL, 1, SSHCFG_COPY_NONE) \
 SSHCONF_STRING(pam_service_name, PAMServiceName, SSHCFG_ALL, SSHCFG_COPY_MATCH)
 #else
 #define SSHD_CONFIG_ENTRIES_PAM \
