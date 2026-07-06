--- lib/gssapi/spnego/spnego_mech.c.orig	2026-01-29 15:18:10.000000000 -0800
+++ lib/gssapi/spnego/spnego_mech.c	2026-06-08 07:36:13.575675000 -0700
@@ -3517,6 +3517,8 @@
 
 	if (k5_der_get_value(&seq, CONTEXT | 0x03, &field)) {
 		*mechListMIC = get_octet_string(&field);
+		if (*mechListMIC == GSS_C_NO_BUFFER)
+			return GSS_S_DEFECTIVE_TOKEN;
 
                 /* Handle Windows 2000 duplicate response token */
                 if (*responseToken &&
