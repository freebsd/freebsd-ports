--- Krb5.xs.orig	2010-01-04 10:29:19.000000000 +0900
+++ Krb5.xs	2015-01-04 06:35:55.000000000 +0900
@@ -16,6 +16,7 @@
 
 #include <errno.h>
 #include "krb5_constants.c"
+#include "krb5-heimdal-compat.h"
 
 #ifdef __cplusplus
 }
@@ -45,6 +46,7 @@
 static krb5_error_code err;
 static krb5_keytab_entry keytab_entry_init;
 
+#ifndef HAVE_HEIMDAL
 /*
  * These are internal Kerberos library functions that aren't prototyped and
  * that we probably shouldn't be calling.  Prototype them with the arguments
@@ -52,6 +54,7 @@
  */
 krb5_error_code krb5_free_krbhst(krb5_context, char * const *);
 krb5_error_code krb5_get_krbhst(krb5_context, const krb5_data *, char ***);
+#endif
 
 /*
  * The following three routines implement a "safehouse" for nested Kerberos
@@ -112,10 +115,18 @@
 
 	CODE:
 	if (e) {
+#ifdef HAVE_HEIMDAL
+		ST(0) = sv_2mortal(newSVpv(krb5_get_error_message(0, e), 0));
+#else
 		ST(0) = sv_2mortal(newSVpv((char *)error_message(e), 0));
+#endif
 	}
 	else {
+#ifdef HAVE_HEIMDAL
+		ST(0) = sv_2mortal(newSVpv(krb5_get_error_message(0, err), 0));
+#else
 		ST(0) = sv_2mortal(newSVpv((char *)error_message(err), 0));
+#endif
 		(void) SvUPGRADE(ST(0), SVt_PVIV);
 		SvIVX(ST(0)) = err;
 		SvIOK_on(ST(0));
@@ -181,14 +192,20 @@
 	char *realm
 
 	PREINIT:
+#ifndef HAVE_HEIMDAL
 	krb5_data realm_data;
+#endif
 	char **hostlist;
 	int i;
 
 	PPCODE:
+#ifdef HAVE_HEIMDAL
+	err = krb5_get_krbhst(context,(const krb5_realm *)realm,&hostlist);
+#else
 	realm_data.data = realm;
 	realm_data.length = strlen(realm);
 	err = krb5_get_krbhst(context,&realm_data,&hostlist);
+#endif
 	if (err || !hostlist) XSRETURN_UNDEF;
 	for (i = 0; hostlist[i]; i++) {
 		XPUSHs(sv_2mortal(newSVpv(hostlist[i],
@@ -202,11 +219,19 @@
 
 	CODE:
 	err = krb5_build_principal_ext(context, &RETVAL,
+#ifdef HAVE_HEIMDAL
+		krb5_realm_length(*krb5_princ_realm(context, p)),
+		krb5_realm_data(*krb5_princ_realm(context, p)),
+		KRB5_TGS_NAME_SIZE, KRB5_TGS_NAME,
+		krb5_realm_length(*krb5_princ_realm(context, p)),
+		krb5_realm_data(*krb5_princ_realm(context, p)),
+#else
 		krb5_princ_realm(context, p)->length,
 		krb5_princ_realm(context, p)->data,
 		KRB5_TGS_NAME_SIZE, KRB5_TGS_NAME,
 		krb5_princ_realm(context, p)->length,
 		krb5_princ_realm(context, p)->data,
+#endif
 		0);
 
 	if (err) XSRETURN_UNDEF;
@@ -519,7 +544,11 @@
 	unsigned short port
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	err = krb5_make_addrport(context,&addr,RETVAL,port);
+#else
 	err = krb5_gen_portaddr(context,addr,(krb5_pointer)&port,&RETVAL);
+#endif
 	if (err) XSRETURN_UNDEF;
 
 	OUTPUT:
@@ -651,14 +680,22 @@
 	Authen::Krb5::Principal p
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	ST(0) = sv_2mortal(newSVpv(krb5_realm_data(p->realm),krb5_realm_length(p->realm)));
+#else
 	ST(0) = sv_2mortal(newSVpv(p->realm.data,p->realm.length));
+#endif
 
 krb5_int32
 type(p)
 	Authen::Krb5::Principal p
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	RETVAL = krb5_principal_get_type(0, p);
+#else
 	RETVAL = p->type;
+#endif
 
 	OUTPUT:
 	RETVAL
@@ -668,14 +705,27 @@
 	Authen::Krb5::Principal p
 
 	PPCODE:
+#ifdef HAVE_HEIMDAL
+	unsigned char buf[256];
+	size_t ret_len;
+
+	if (length_Principal(p) > 0) {
+		int len = length_Principal(p);
+#else
 	if (p->length > 0) {
 		int len = p->length;
 		krb5_data *data;
-
+#endif
+#ifdef HAVE_HEIMDAL
+		EXTEND(sp,1);
+		encode_Principal(buf, sizeof(buf), p, &ret_len);
+		PUSHs(sv_2mortal(newSVpv((const char *)buf, ret_len)));
+#else
 		EXTEND(sp,len);
 		for (data = p->data; len--; data++) {
 			PUSHs(sv_2mortal(newSVpv(data->data,data->length)));
 		}
+#endif
 	}
 
 void
@@ -811,7 +861,11 @@
 	Authen::Krb5::KeyBlock kb
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	RETVAL = length_EncryptionKey(kb);
+#else
 	RETVAL = kb->length;
+#endif
 
 	OUTPUT:
 	RETVAL
@@ -821,15 +875,28 @@
 	Authen::Krb5::KeyBlock kb
 
 	PPCODE:
+#ifdef HAVE_HEIMDAL
+	unsigned char buf[256];
+	size_t len;
+
+	len = length_EncryptionKey(kb);
+	decode_EncryptionKey(buf, sizeof(buf), kb, &len);
+	XPUSHs(newSVpvn((char*)buf, len));
+#else
 	/* sv_2mortal here causes 'Attempt to free unreferenced scalar' later */
 	XPUSHs(newSVpvn((char*)(kb->contents), kb->length));
+#endif
 
 int
 enctype(kb)
 	Authen::Krb5::KeyBlock kb
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	RETVAL = (int)kb->keytype;
+#else
 	RETVAL = (int)kb->enctype;
+#endif
 
 	OUTPUT:
 	RETVAL
@@ -839,14 +906,32 @@
 	Authen::Krb5::KeyBlock kb
 
 	PREINIT:
+#ifdef HAVE_HEIMDAL
+	char *buf;
+	krb5_enctype **enctypes;
+	unsigned int ret_len;
+#else
 	char buf[256];
+#endif
 
 	PPCODE:
+#ifdef HAVE_HEIMDAL
+	err = krb5_keytype_to_enctypes(0, kb->keytype, &ret_len, enctypes);
+	if (err) {
+		XSRETURN_UNDEF;
+	}
+	err = krb5_enctype_to_string(0, *enctypes[0], &buf);
+	free(enctypes);
+#else
 	err = krb5_enctype_to_string(kb->enctype, buf, 255);
+#endif
 	if (err) {
 		XSRETURN_UNDEF;
 	}
 	XPUSHs(newSVpv(buf, 0));
+#ifdef HAVE_HEIMDAL
+	free(buf);
+#endif
 
 void
 DESTROY(kb)
@@ -1001,7 +1086,11 @@
 	Authen::Krb5::Ticket t
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	RETVAL = &t->ticket;
+#else
 	RETVAL = t->enc_part2;
+#endif
 
 	OUTPUT:
 	RETVAL
@@ -1023,7 +1112,12 @@
 	Authen::Krb5::EncTktPart etp
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	RETVAL->name = etp->cname;
+	RETVAL->realm = etp->crealm;
+#else
 	RETVAL = etp->client;
+#endif
 
 	OUTPUT:
 	RETVAL
@@ -1034,7 +1128,11 @@
 
 	CODE:
 	if (etp && should_free((SV *)etp)) {
+#ifdef HAVE_HEIMDAL
+		free_EncTicketPart(etp);
+#else
 		krb5_free_enc_tkt_part(context,etp);
+#endif
 		freed((SV *)etp);
 	}
 
@@ -1048,8 +1146,15 @@
 
 	CODE:
 	if (!New(0,RETVAL,1,krb5_address)) XSRETURN_UNDEF;
+#ifdef HAVE_HEIMDAL
+	size_t len, ret_len;
+	unsigned char *cp = (unsigned char *)SvPV(contents,ret_len);
+	decode_HostAddress(cp, ret_len, RETVAL, &len);
+	RETVAL->addr_type = addrtype;
+#else
 	RETVAL->addrtype = addrtype;
 	RETVAL->contents = (krb5_octet *)SvPV(contents,RETVAL->length);
+#endif
 	
 	OUTPUT:
 	RETVAL
@@ -1072,7 +1177,16 @@
 	Authen::Krb5::Keyblock keyblock
 
         CODE:
+#ifdef HAVE_HEIMDAL
+	krb5int32	keytype;
+	krb5_enctype	**enctypes;
+	unsigned	ret_len;
+
+	krb5_keytype_to_enctypes(0, keyblock->keytype, &ret_len, enctypes);
+	RETVAL = *enctypes[0];
+#else
         RETVAL = keyblock->enctype;
+#endif
 
         OUTPUT:
         RETVAL
@@ -1082,7 +1196,11 @@
         Authen::Krb5::Keyblock keyblock
 
         CODE:
+#ifdef HAVE_HEIMDAL
+        RETVAL = length_EncryptionKey(keyblock);
+#else
         RETVAL = keyblock->length;
+#endif
 
         OUTPUT:
         RETVAL
@@ -1092,9 +1210,19 @@
         Authen::Krb5::Keyblock keyblock
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	unsigned char buf[256];
+	size_t ret_len;
+
+	if (length_EncryptionKey(keyblock) == 0)
+		XSRETURN_UNDEF;
+	encode_EncryptionKey(buf, sizeof(buf), keyblock, &ret_len); 
+	RETVAL = newSVpv((char *)buf, ret_len);
+#else
 	if (keyblock->contents == NULL)
 		XSRETURN_UNDEF;
 	RETVAL = newSVpv((char *) keyblock->contents, keyblock->length);
+#endif
 
 	OUTPUT:
 	RETVAL
@@ -1104,11 +1232,19 @@
 	Authen::Krb5::Keyblock	keyblock
 
         CODE:
+#ifdef HAVE_HEIMDAL
+	int len;
+
+	len = length_EncryptionKey(keyblock);
+	if (len > 0)
+		free_EncryptionKey(keyblock);
+#else
 	if (keyblock->contents) {
 		memset(keyblock->contents, 0, keyblock->length);
 		free(keyblock->contents);
 		keyblock->contents = NULL;
 	}
+#endif
 
 MODULE = Authen::Krb5   PACKAGE = Authen::Krb5::Keytab
 
@@ -1236,7 +1372,11 @@
         *RETVAL = keytab_entry_init;
 	RETVAL->principal = principal;
 	RETVAL->vno = vno;
+#ifdef HAVE_HEIMDAL
+	RETVAL->keyblock = *key;
+#else
         RETVAL->key = *key;
+#endif
 
         can_free((SV *)RETVAL);
 	
@@ -1281,7 +1421,11 @@
 	Authen::Krb5::KeytabEntry entry
 
         CODE:
+#ifdef HAVE_HEIMDAL
+        err = krb5_copy_keyblock(context, &entry->keyblock, &RETVAL);
+#else
         err = krb5_copy_keyblock(context, &entry->key, &RETVAL);
+#endif
         if (err)
                 XSRETURN_UNDEF;
         can_free((SV *)RETVAL);
@@ -1380,14 +1524,19 @@
 	PREINIT:
 	krb5_error_code retval;
 	krb5_ticket *t;
+#ifdef HAVE_HEIMDAL
+	size_t ret_len;
+#endif
 
 	CODE:	
 	if (!New(0,t,1,krb5_ticket)) XSRETURN_UNDEF;
-
+#ifdef HAVE_HEIMDAL
+	retval = krb5_decode_EncTicketPart(0, &t, sizeof(*t),
+	    (struct EncTicketPart *)&cred->ticket, &ret_len);
+#else
 	retval = krb5_decode_ticket(&cred->ticket, &t);
-
+#endif
 	RETVAL = t;
-
 	can_free((SV *)RETVAL);
 
 	OUTPUT:
@@ -1398,7 +1547,11 @@
 	Authen::Krb5::Creds cred
 
 	CODE:
+#ifdef HAVE_HEIMDAL
+	RETVAL = &cred->session;
+#else
 	RETVAL = &cred->keyblock;
+#endif
 
         can_free((SV *)RETVAL);
 
