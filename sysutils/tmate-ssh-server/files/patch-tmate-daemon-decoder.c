--- tmate-daemon-decoder.c.orig	2019-02-01 22:30:53 UTC
+++ tmate-daemon-decoder.c
@@ -39,11 +39,11 @@ static void tmate_header(struct tmate_session *session
 
 	tmate_notify("Note: clear your terminal before sharing readonly access");
 	tmate_notify("ssh session read only: %s", tmp);
+	tmate_set_env("tmate_ssh_ro", tmp);
 
 	sprintf(tmp, "ssh%s %s@%s", port_arg, session->session_token, tmate_settings->tmate_host);
 	tmate_notify("ssh session: %s", tmp);
 
-	tmate_set_env("tmate_ssh_ro", tmp);
 	tmate_set_env("tmate_ssh", tmp);
 
 	tmate_send_client_ready();
