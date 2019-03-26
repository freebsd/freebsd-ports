--- settings.c.orig	2019-03-16 12:26:35 UTC
+++ settings.c
@@ -592,21 +592,25 @@ void save_open_settings(settings_w *sesskey, Conf *con
     write_setting_b(sesskey, "Compression", conf_get_bool(conf, CONF_compression));
     write_setting_b(sesskey, "TryAgent", conf_get_bool(conf, CONF_tryagent));
     write_setting_b(sesskey, "AgentFwd", conf_get_bool(conf, CONF_agentfwd));
+#ifndef NO_GSSAPI
     write_setting_b(sesskey, "GssapiFwd", conf_get_bool(conf, CONF_gssapifwd));
+#endif
     write_setting_b(sesskey, "ChangeUsername", conf_get_bool(conf, CONF_change_username));
     wprefs(sesskey, "Cipher", ciphernames, CIPHER_MAX, conf, CONF_ssh_cipherlist);
     wprefs(sesskey, "KEX", kexnames, KEX_MAX, conf, CONF_ssh_kexlist);
     wprefs(sesskey, "HostKey", hknames, HK_MAX, conf, CONF_ssh_hklist);
     write_setting_i(sesskey, "RekeyTime", conf_get_int(conf, CONF_ssh_rekey_time));
+#ifndef NO_GSSAPI
     write_setting_i(sesskey, "GssapiRekey", conf_get_int(conf, CONF_gssapirekey));
+#endif
     write_setting_s(sesskey, "RekeyBytes", conf_get_str(conf, CONF_ssh_rekey_data));
     write_setting_b(sesskey, "SshNoAuth", conf_get_bool(conf, CONF_ssh_no_userauth));
     write_setting_b(sesskey, "SshBanner", conf_get_bool(conf, CONF_ssh_show_banner));
     write_setting_b(sesskey, "AuthTIS", conf_get_bool(conf, CONF_try_tis_auth));
     write_setting_b(sesskey, "AuthKI", conf_get_bool(conf, CONF_try_ki_auth));
+#ifndef NO_GSSAPI
     write_setting_b(sesskey, "AuthGSSAPI", conf_get_bool(conf, CONF_try_gssapi_auth));
     write_setting_b(sesskey, "AuthGSSAPIKEX", conf_get_bool(conf, CONF_try_gssapi_kex));
-#ifndef NO_GSSAPI
     wprefs(sesskey, "GSSLibs", gsslibkeywords, ngsslibs, conf, CONF_ssh_gsslist);
     write_setting_filename(sesskey, "GSSCustom", conf_get_filename(conf, CONF_ssh_gss_custom));
 #endif
@@ -937,7 +941,9 @@ void load_open_settings(settings_r *sesskey, Conf *con
     gppb(sesskey, "TryAgent", true, conf, CONF_tryagent);
     gppb(sesskey, "AgentFwd", false, conf, CONF_agentfwd);
     gppb(sesskey, "ChangeUsername", false, conf, CONF_change_username);
+#ifndef NO_GSSAPI
     gppb(sesskey, "GssapiFwd", false, conf, CONF_gssapifwd);
+#endif
     gprefs(sesskey, "Cipher", "\0",
 	   ciphernames, CIPHER_MAX, conf, CONF_ssh_cipherlist);
     {
@@ -990,7 +996,9 @@ void load_open_settings(settings_r *sesskey, Conf *con
     gprefs(sesskey, "HostKey", "ed25519,ecdsa,rsa,dsa,WARN",
            hknames, HK_MAX, conf, CONF_ssh_hklist);
     gppi(sesskey, "RekeyTime", 60, conf, CONF_ssh_rekey_time);
+#ifndef NO_GSSAPI
     gppi(sesskey, "GssapiRekey", GSS_DEF_REKEY_MINS, conf, CONF_gssapirekey);
+#endif
     gpps(sesskey, "RekeyBytes", "1G", conf, CONF_ssh_rekey_data);
     {
 	/* SSH-2 only by default */
@@ -1007,9 +1015,9 @@ void load_open_settings(settings_r *sesskey, Conf *con
     gppb(sesskey, "SshBanner", true, conf, CONF_ssh_show_banner);
     gppb(sesskey, "AuthTIS", false, conf, CONF_try_tis_auth);
     gppb(sesskey, "AuthKI", true, conf, CONF_try_ki_auth);
+#ifndef NO_GSSAPI
     gppb(sesskey, "AuthGSSAPI", true, conf, CONF_try_gssapi_auth);
     gppb(sesskey, "AuthGSSAPIKEX", true, conf, CONF_try_gssapi_kex);
-#ifndef NO_GSSAPI
     gprefs(sesskey, "GSSLibs", "\0",
 	   gsslibkeywords, ngsslibs, conf, CONF_ssh_gsslist);
     gppfile(sesskey, "GSSCustom", conf, CONF_ssh_gss_custom);
