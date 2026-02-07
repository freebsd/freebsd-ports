--- tmate-ssh-server.c.orig	2020-04-27 23:54:26 UTC
+++ tmate-ssh-server.c
@@ -242,6 +242,12 @@ static void client_bootstrap(struct tmate_session *_se
 
 	ssh_options_set(session, SSH_OPTIONS_TIMEOUT, &grace_period);
 	ssh_options_set(session, SSH_OPTIONS_COMPRESSION, "yes");
+	ssh_options_set(session, SSH_OPTIONS_KEY_EXCHANGE, "curve25519-sha256@libssh.org,diffie-hellman-group18-sha512,diffie-hellman-group14-sha256,diffie-hellman-group16-sha512");
+	ssh_options_set(session, SSH_OPTIONS_CIPHERS_C_S, "aes256-gcm@openssh.com,aes128-gcm@openssh.com,chacha20-poly1305@openssh.com,aes256-ctr,aes192-ctr,aes128-ctr");
+	ssh_options_set(session, SSH_OPTIONS_CIPHERS_S_C, "aes256-gcm@openssh.com,aes128-gcm@openssh.com,chacha20-poly1305@openssh.com,aes256-ctr,aes192-ctr,aes128-ctr");
+	ssh_options_set(session, SSH_OPTIONS_HMAC_S_C, "hmac-sha2-512-etm@openssh.com,hmac-sha2-256-etm@openssh.com,umac-128-etm@openssh.com");
+	ssh_options_set(session, SSH_OPTIONS_HMAC_C_S, "hmac-sha2-512-etm@openssh.com,hmac-sha2-256-etm@openssh.com,umac-128-etm@openssh.com");
+	ssh_options_set(session, SSH_OPTIONS_HOSTKEYS, "ecdsa-sha2-nistp384-cert-v01@openssh.com,ecdsa-sha2-nistp521-cert-v01@openssh.com,ssh-ed25519-cert-v01@openssh.com,ssh-rsa-cert-v01@openssh.com,ecdsa-sha2-nistp384,ecdsa-sha2-nistp521,ssh-ed25519,ssh-rsa");
 
 	ssh_set_auth_methods(client->session, SSH_AUTH_METHOD_NONE |
 					      SSH_AUTH_METHOD_PUBLICKEY);
@@ -417,7 +423,6 @@ static ssh_bind prepare_ssh(const char *keys_dir, cons
 	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_BANNER, TMATE_SSH_BANNER);
 	ssh_bind_options_set(bind, SSH_BIND_OPTIONS_LOG_VERBOSITY, &ssh_log_level);
 
-	ssh_import_key(bind, keys_dir, "ssh_host_rsa_key");
 	ssh_import_key(bind, keys_dir, "ssh_host_ed25519_key");
 
 	if (ssh_bind_listen(bind) < 0)
