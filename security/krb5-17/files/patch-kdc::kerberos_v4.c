Index: kdc/kerberos_v4.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/kdc/kerberos_v4.c,v
retrieving revision 5.68.2.3.2.1
diff -u -r5.68.2.3.2.1 kerberos_v4.c
--- kdc/kerberos_v4.c	2002/08/15 21:28:54	5.68.2.3.2.1
+++ kdc/kerberos_v4.c	2002/10/15 23:32:45
@@ -149,7 +149,7 @@
 
 void kerberos_v4 PROTOTYPE((struct sockaddr_in *, KTEXT));
 void kerb_err_reply PROTOTYPE((struct sockaddr_in *, KTEXT, long, char *));
-static int set_tgtkey PROTOTYPE((char *, krb5_kvno));
+static int set_tgtkey PROTOTYPE((char *, krb5_kvno, krb5_boolean));
 
 /* Attributes converted from V5 to V4 - internal representation */
 #define V4_KDB_REQUIRES_PREAUTH  0x1
@@ -182,6 +182,7 @@
 
 static const int v4mode_table_nents = sizeof(v4mode_table)/
 				      sizeof(v4mode_table[0]);
+static int allow_v4_crossrealm = 0;
 
 void process_v4_mode(progname, string)
     const char          *progname;
@@ -210,6 +211,11 @@
     return;
 }
 
+void enable_v4_crossrealm ( char *programname) {
+    allow_v4_crossrealm = 1;
+    krb5_klog_syslog(LOG_ERR, "Enabling v4 cross-realm compatibility; this is a known security hole");
+}
+
 krb5_error_code
 process_v4( pkt, client_fulladdr, is_secondary, resp)
 const krb5_data *pkt;
@@ -401,6 +407,14 @@
 #define MIN5 300
 #define HR21 255
 
+/*
+ * Previously this code returned either a v4 key or a v5 key  and you
+ * could tell from the enctype of the v5 key whether the v4 key was
+ * useful.  Now we return both keys so the code can try both des3 and
+ * des decryption.  We fail if the ticket doesn't have a v4 key.
+ * Also, note as a side effect, the v5 key is basically useless  in
+ * the client case.  It is still returned so the caller can free it.
+ */
 static int
 kerb_get_principal(name, inst, principal, maxn, more, k5key, kvno, issrv)
     char   *name;               /* could have wild card */
@@ -482,8 +496,28 @@
 	    return(0);
 	}
     } else {
-	/* XXX yes I know this is a hardcoded search order */
-	if (krb5_dbe_find_enctype(kdc_context, &entries,
+	if ( krb5_dbe_find_enctype(kdc_context, &entries,
+				  ENCTYPE_DES_CBC_CRC,
+				  KRB5_KDB_SALTTYPE_V4, kvno, &pkey) &&
+	    krb5_dbe_find_enctype(kdc_context, &entries,
+				  ENCTYPE_DES_CBC_CRC,
+				  -1, kvno, &pkey)) {
+	    lt = klog(L_KRB_PERR,
+		      "KDC V4: failed to find key for %s.%s #%d",
+		      name, inst, kvno);
+	    krb5_db_free_principal(kdc_context, &entries, nprinc);
+	    return(0);
+	}
+    }
+
+    if (!compat_decrypt_key(pkey, k, k5key, issrv)) {
+ 	memcpy( &principal->key_low, k, LONGLEN);
+       	memcpy( &principal->key_high, (krb5_ui_4 *) k + 1, LONGLEN);
+    }
+    memset(k, 0, sizeof k);
+    if (issrv) {
+	krb5_free_keyblock_contents (kdc_context, k5key);
+      	if (krb5_dbe_find_enctype(kdc_context, &entries,
 				  ENCTYPE_DES3_CBC_RAW,
 				  -1, kvno, &pkey) &&
 	    krb5_dbe_find_enctype(kdc_context, &entries,
@@ -504,12 +538,10 @@
 	    krb5_db_free_principal(kdc_context, &entries, nprinc);
 	    return(0);
 	}
+	compat_decrypt_key(pkey, k, k5key, issrv);
+	memset (k, 0, sizeof k);
     }
 
-    if (!compat_decrypt_key(pkey, k, k5key, issrv)) {
- 	memcpy( &principal->key_low, k, LONGLEN);
-       	memcpy( &principal->key_high, (krb5_ui_4 *) k + 1, LONGLEN);
-    }
     /* convert v5's entries struct to v4's Principal struct:
      * v5's time-unit for lifetimes is 1 sec, while v4 uses 5 minutes.
      */
@@ -746,21 +778,14 @@
 	    kdb_encrypt_key(key, key, master_key,
 			    master_key_schedule, DECRYPT);
 	    /* construct and seal the ticket */
-	    if (K4KDC_ENCTYPE_OK(k5key.enctype)) {
-		krb_create_ticket(tk, k_flags, a_name_data.name,
-				  a_name_data.instance, local_realm,
-				  client_host.s_addr, (char *) session_key,
-				  lifetime, kerb_time.tv_sec,
-				  s_name_data.name, s_name_data.instance,
-				  key);
-	    } else {
-		krb_cr_tkt_krb5(tk, k_flags, a_name_data.name,
-				a_name_data.instance, local_realm,
-				client_host.s_addr, (char *) session_key,
-				lifetime, kerb_time.tv_sec,
-				s_name_data.name, s_name_data.instance,
-				&k5key);
-	    }
+	    /* We always issue des tickets; the 3des tickets are a broken hack*/
+	    krb_create_ticket(tk, k_flags, a_name_data.name,
+			      a_name_data.instance, local_realm,
+			      client_host.s_addr, (char *) session_key,
+			      lifetime, kerb_time.tv_sec,
+			      s_name_data.name, s_name_data.instance,
+			      key);
+
 	    krb5_free_keyblock_contents(kdc_context, &k5key);
 	    memset(key, 0, sizeof(key));
 	    memset(key_s, 0, sizeof(key_s));
@@ -840,8 +865,15 @@
 	    strncpy(tktrlm, (char *)auth->dat + 3, REALM_SZ);
 	    tktrlm[REALM_SZ-1] = '\0';
 	    kvno = (krb5_kvno)auth->dat[2];
-	    if (set_tgtkey(tktrlm, kvno)) {
-		lt = klog(L_ERR_UNK,
+	    if ((!allow_v4_crossrealm)&&strcmp(tktrlm, local_realm) != 0) {
+	      lt = klog(L_ERR_UNK,
+			"Cross realm ticket from %s denied by policy,", tktrlm);
+	      kerb_err_reply(client, pkt,
+			       KERB_ERR_PRINCIPAL_UNKNOWN, lt);
+		return;
+	    }
+	    if (set_tgtkey(tktrlm, kvno, 0)) {
+	      lt = klog(L_ERR_UNK,
 			  "FAILED set_tgtkey realm %s, kvno %d. Host: %s ",
 			  tktrlm, kvno, inet_ntoa(client_host));
 		/* no better error code */
@@ -851,6 +883,19 @@
 	    }
 	    kerno = krb_rd_req(auth, "krbtgt", tktrlm, client_host.s_addr,
 		ad, 0);
+	    if (kerno) {
+		if (set_tgtkey(tktrlm, kvno, 1)) {
+		    lt = klog(L_ERR_UNK,
+			      "FAILED 3des set_tgtkey realm %s, kvno %d. Host: %s ",
+			      tktrlm, kvno, inet_ntoa(client_host));
+		    /* no better error code */
+		    kerb_err_reply(client, pkt,
+				   KERB_ERR_PRINCIPAL_UNKNOWN, lt);
+		    return;
+		}
+		kerno = krb_rd_req(auth, "krbtgt", tktrlm, client_host.s_addr,
+				   ad, 0);
+	    }
 
 	    if (kerno) {
 		klog(L_ERR_UNK, "FAILED krb_rd_req from %s: %s",
@@ -916,21 +961,13 @@
 	    des_new_random_key(session_key);
 #endif
 
-	    if (K4KDC_ENCTYPE_OK(k5key.enctype)) {
-		krb_create_ticket(tk, k_flags, ad->pname, ad->pinst,
-				  ad->prealm, client_host.s_addr,
-				  (char *) session_key, lifetime,
-				  kerb_time.tv_sec,
-				  s_name_data.name, s_name_data.instance,
-				  key);
-	    } else {
-		krb_cr_tkt_krb5(tk, k_flags, ad->pname, ad->pinst,
-				ad->prealm, client_host.s_addr,
-				(char *) session_key, lifetime,
-				kerb_time.tv_sec,
-				s_name_data.name, s_name_data.instance,
-				&k5key);
-	    }
+	    /* ALways issue des tickets*/
+	    krb_create_ticket(tk, k_flags, ad->pname, ad->pinst,
+			      ad->prealm, client_host.s_addr,
+			      (char *) session_key, lifetime,
+			      kerb_time.tv_sec,
+			      s_name_data.name, s_name_data.instance,
+			      key);
 	    krb5_free_keyblock_contents(kdc_context, &k5key);
 	    memset(key, 0, sizeof(key));
 	    memset(key_s, 0, sizeof(key_s));
@@ -1138,20 +1175,22 @@
 
 /* Set the key for krb_rd_req so we can check tgt */
 static int
-set_tgtkey(r, kvno)
+set_tgtkey(r, kvno, use_3des)
     char   *r;			/* Realm for desired key */
     krb5_kvno kvno;
+    krb5_boolean use_3des;
 {
     int     n;
     static char lastrealm[REALM_SZ] = "";
     static int last_kvno = 0;
+    static krb5_boolean last_use_3des = 0;
     Principal p_st;
     Principal *p = &p_st;
     C_Block key;
     krb5_keyblock k5key;
 
     k5key.contents = NULL;
-    if (!strcmp(lastrealm, r) && last_kvno == kvno)
+    if (!strcmp(lastrealm, r) && last_kvno == kvno && last_use_3des == use_3des)
 	return (KSUCCESS);
 
 /*  log("Getting key for %s", r); */
@@ -1173,11 +1212,12 @@
 	return KFAILURE;
     }
 
-    if (!K4KDC_ENCTYPE_OK(k5key.enctype)) {
+    if (use_3des&&!K4KDC_ENCTYPE_OK(k5key.enctype)) {
 	krb_set_key_krb5(kdc_context, &k5key);
 	strncpy(lastrealm, r, sizeof(lastrealm) - 1);
 	lastrealm[sizeof(lastrealm) - 1] = '\0';
 	last_kvno = kvno;
+	last_use_3des = use_3des;
     } else {
 	/* unseal tgt key from master key */
 	memcpy(key,                &p->key_low,  4);
