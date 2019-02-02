--- tmate-ssh-client.c.orig	2016-03-29 03:30:07 UTC
+++ tmate-ssh-client.c
@@ -3,6 +3,7 @@
 #include <stdio.h>
 #include <event.h>
 #include <assert.h>
+#include <netinet/in.h>
 
 #include "tmate.h"
 #include "window-copy.h"
@@ -195,6 +196,7 @@ static void on_ssh_client_event(struct tmate_ssh_clien
 	ssize_t hash_len;
 	char *hash_str;
 	const char *server_hash_str;
+	const char *key_type_name;
 	int match;
 
 	int verbosity = SSH_LOG_NOLOG + log_get_level();
@@ -257,43 +259,80 @@ static void on_ssh_client_event(struct tmate_ssh_clien
 		}
 
 	case SSH_AUTH_SERVER:
+		tmate_debug("Starting SSH_AUTH_SERVER");
 		if (ssh_get_publickey(session, &pubkey) < 0)
 			tmate_fatal("ssh_get_publickey");
 
-		if (ssh_get_publickey_hash(pubkey, SSH_PUBLICKEY_HASH_MD5, &hash, &hash_len) < 0) {
+		if (ssh_get_publickey_hash(pubkey, SSH_PUBLICKEY_HASH_SHA1, &hash, &hash_len) < 0) {
+			tmate_debug("failed to get public key hash");
 			kill_ssh_client(client, "Cannot authenticate server");
 			return;
 		}
+		tmate_debug("got public key hash");
 
 		hash_str = ssh_get_hexa(hash, hash_len);
 		if (!hash_str)
 			tmate_fatal("malloc failed");
 
 		key_type = ssh_key_type(pubkey);
+		key_type_name = ssh_key_type_to_char(key_type);
+		if (key_type_name == NULL) {
+			tmate_debug("failed to get public key type name");
+			return;
+		}
 
 		switch (key_type) {
 		case SSH_KEYTYPE_RSA:
 			server_hash_str = options_get_string(global_options,
 						"tmate-server-rsa-fingerprint");
+			tmate_debug("found rsa fingerprint");
 			break;
 		case SSH_KEYTYPE_ECDSA:
 			server_hash_str = options_get_string(global_options,
 						"tmate-server-ecdsa-fingerprint");
+			tmate_debug("found ecdsa fingerprint");
 			break;
+		case SSH_KEYTYPE_DSS:
+			server_hash_str = options_get_string(global_options,
+						"tmate-server-dss-fingerprint");
+			tmate_debug("found dss fingerprint");
+			break;
+		case SSH_KEYTYPE_ED25519:
+			server_hash_str = options_get_string(global_options,
+						"tmate-server-ed25519-fingerprint");
+			tmate_debug("found ed25519 fingerprint");
+			break;
+		case SSH_KEYTYPE_DSS_CERT01:
+			server_hash_str = options_get_string(global_options,
+						"tmate-server-dss-cert01-fingerprint");
+			tmate_debug("found dss_cert01 fingerprint");
+			break;
+		case SSH_KEYTYPE_RSA_CERT01:
+			server_hash_str = options_get_string(global_options,
+						"tmate-server-rsa-cert01-fingerprint");
+			tmate_debug("found rsa_cert01 fingerprint");
+			break;
+		case SSH_KEYTYPE_UNKNOWN:
+			tmate_debug("found unknown fingerprint?");
+			break;
 		default:
 			server_hash_str = "";
+			tmate_debug("found no fingerprint?");
 		}
 
 		match = !strcmp(hash_str, server_hash_str);
 
 		ssh_key_free(pubkey);
 		ssh_clean_pubkey_hash(&hash);
-		free(hash_str);
 
 		if (!match) {
-			kill_ssh_client(client, "Cannot authenticate server");
+			tmate_debug("Key mismatch: type: %s expected: %s found: %s", key_type_name, server_hash_str, hash_str);
+			kill_ssh_client(client, "Cannot authenticate server: Key mismatch: type: %s expected: %s found: %s", key_type_name, server_hash_str, hash_str);
+			free(hash_str);
 			return;
 		}
+
+		free(hash_str);
 
 		/*
 		 * At this point, we abort other connection attempts to the
