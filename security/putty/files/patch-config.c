--- config.c.orig	2019-03-16 12:26:32 UTC
+++ config.c
@@ -2442,10 +2442,12 @@ void setup_config_box(struct controlbox *b, bool midse
 			      HELPCTX(ssh_kexlist),
 			      kexlist_handler, P(NULL));
             c->listbox.height = KEX_MAX;
+#ifndef NO_GSSAPI
 	    ctrl_checkbox(s, "Attempt GSSAPI key exchange",
 			  'k', HELPCTX(ssh_gssapi),
 			  conf_checkbox_handler,
 			  I(CONF_try_gssapi_kex));
+#endif
 
 	    s = ctrl_getset(b, "Connection/SSH/Kex", "repeat",
 			    "Options controlling key re-exchange");
@@ -2455,11 +2457,13 @@ void setup_config_box(struct controlbox *b, bool midse
 			 conf_editbox_handler,
 			 I(CONF_ssh_rekey_time),
 			 I(-1));
+#ifndef NO_GSSAPI
             ctrl_editbox(s, "Minutes between GSS checks (0 for never)", NO_SHORTCUT, 20,
                          HELPCTX(ssh_kex_repeat),
                          conf_editbox_handler,
                          I(CONF_gssapirekey),
                          I(-1));
+#endif
 	    ctrl_editbox(s, "Max data before rekey (0 for no limit)", 'x', 20,
 			 HELPCTX(ssh_kex_repeat),
 			 conf_editbox_handler,
