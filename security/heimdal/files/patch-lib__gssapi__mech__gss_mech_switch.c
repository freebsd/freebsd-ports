--- lib/gssapi/mech/gss_mech_switch.c.orig	2010-11-05 11:16:35.000000000 +0100
+++ lib/gssapi/mech/gss_mech_switch.c	2010-11-05 11:16:52.000000000 +0100
@@ -334,6 +334,7 @@
 		OPTSYM(set_sec_context_option);
 		OPTSYM(set_cred_option);
 		OPTSYM(pseudo_random);
+		OPTSYM(pname_to_uid);
 		OPTSYM(wrap_iov);
 		OPTSYM(unwrap_iov);
 		OPTSYM(wrap_iov_length);
