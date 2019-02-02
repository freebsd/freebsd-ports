--- tmate-ssh-server.c.orig	2018-11-19 02:28:35 UTC
+++ tmate-ssh-server.c
@@ -8,6 +8,8 @@
 #include <stdio.h>
 #include <event.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/signal.h>
 
 #include "tmate.h"
 
@@ -252,6 +254,10 @@ static void client_bootstrap(struct tmate_session *_se
 
 	ssh_options_set(session, SSH_OPTIONS_TIMEOUT, &grace_period);
 	ssh_options_set(session, SSH_OPTIONS_COMPRESSION, "yes");
+	ssh_options_set(session, SSH_OPTIONS_KEY_EXCHANGE, "curve25519-sha256@libssh.org,diffie-hellman-group18-sha512,diffie-hellman-group14-sha256,diffie-hellman-group16-sha512");
+	ssh_options_set(session, SSH_OPTIONS_CIPHERS_C_S, "aes256-gcm@openssh.com,aes128-gcm@openssh.com,chacha20-poly1305@openssh.com,aes256-ctr,aes192-ctr,aes128-ctr");
+	ssh_options_set(session, SSH_OPTIONS_CIPHERS_S_C, "aes256-gcm@openssh.com,aes128-gcm@openssh.com,chacha20-poly1305@openssh.com,aes256-ctr,aes192-ctr,aes128-ctr");
+	ssh_options_set(session, SSH_OPTIONS_HOSTKEYS, "ecdsa-sha2-nistp384-cert-v01@openssh.com,ecdsa-sha2-nistp521-cert-v01@openssh.com,ssh-ed25519-cert-v01@openssh.com,ssh-rsa-cert-v01@openssh.com,ecdsa-sha2-nistp384,ecdsa-sha2-nistp521,ssh-ed25519,ssh-rsa");
 
 	ssh_set_auth_methods(client->session, SSH_AUTH_METHOD_PUBLICKEY);
 
@@ -323,6 +329,9 @@ static ssh_bind prepare_ssh(const char *keys_dir, cons
 	ssh_bind bind;
 	char buffer[PATH_MAX];
 	int ssh_log_level;
+	ssh_key rsakey = NULL;
+	ssh_key ecdsakey = NULL;
+	ssh_key ed25519key = NULL;
 
 	ssh_log_level = SSH_LOG_WARNING + max(log_get_level() - LOG_NOTICE, 0);
 
@@ -339,10 +348,16 @@ static ssh_bind prepare_ssh(const char *keys_dir, cons
 	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_LOG_VERBOSITY, &ssh_log_level);
 
 	sprintf(buffer, "%s/ssh_host_rsa_key", keys_dir);
-	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_RSAKEY, buffer);
+	ssh_pki_import_privkey_file(buffer, NULL, NULL, NULL, &rsakey);
+	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_IMPORT_KEY, rsakey);
 
+	sprintf(buffer, "%s/ssh_host_ed25519_key", keys_dir);
+	ssh_pki_import_privkey_file(buffer, NULL, NULL, NULL, &ed25519key);
+	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_IMPORT_KEY, ed25519key);
+
 	sprintf(buffer, "%s/ssh_host_ecdsa_key", keys_dir);
-	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_ECDSAKEY, buffer);
+	ssh_pki_import_privkey_file(buffer, NULL, NULL, NULL, &ecdsakey);
+	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_IMPORT_KEY, ecdsakey);
 
 	if (ssh_bind_listen(bind) < 0)
 		tmate_fatal("Error listening to socket: %s\n", ssh_get_error(bind));
