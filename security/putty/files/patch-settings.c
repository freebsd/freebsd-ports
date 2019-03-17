--- settings.c.orig	2019-03-16 12:26:35 UTC
+++ settings.c
@@ -990,7 +990,9 @@ void load_open_settings(settings_r *sesskey, Conf *con
     gprefs(sesskey, "HostKey", "ed25519,ecdsa,rsa,dsa,WARN",
            hknames, HK_MAX, conf, CONF_ssh_hklist);
     gppi(sesskey, "RekeyTime", 60, conf, CONF_ssh_rekey_time);
+#ifndef NO_GSSAPI
     gppi(sesskey, "GssapiRekey", GSS_DEF_REKEY_MINS, conf, CONF_gssapirekey);
+#endif
     gpps(sesskey, "RekeyBytes", "1G", conf, CONF_ssh_rekey_data);
     {
 	/* SSH-2 only by default */
