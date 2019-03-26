--- ssh2userauth.c.orig	2019-03-16 12:26:35 UTC
+++ ssh2userauth.c
@@ -613,8 +613,10 @@ static void ssh2_userauth_process_queue(PacketProtocol
                  * Scan it for method identifiers we know about.
                  */
                 bool srv_pubkey = false, srv_passwd = false;
-                bool srv_keyb_inter = false, srv_gssapi = false;
-                bool srv_gssapi_keyex_auth = false;
+                bool srv_keyb_inter = false;
+#ifndef NO_GSSAPI
+                bool srv_gssapi = false, srv_gssapi_keyex_auth = false;
+#endif
 
                 for (ptrlen method; get_commasep_word(&methods, &method) ;) {
                     if (ptrlen_eq_string(method, "publickey"))
@@ -623,10 +625,12 @@ static void ssh2_userauth_process_queue(PacketProtocol
                         srv_passwd = true;
                     else if (ptrlen_eq_string(method, "keyboard-interactive"))
                         srv_keyb_inter = true;
+#ifndef NO_GSSAPI
                     else if (ptrlen_eq_string(method, "gssapi-with-mic"))
                         srv_gssapi = true;
                     else if (ptrlen_eq_string(method, "gssapi-keyex"))
                         srv_gssapi_keyex_auth = true;
+#endif
                 }
 
                 /*
