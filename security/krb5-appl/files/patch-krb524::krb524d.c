Index: krb524/krb524d.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/krb524/krb524d.c,v
retrieving revision 1.40.4.3
diff -u -r1.40.4.3 krb524d.c
--- krb524/krb524d.c	2002/08/29 06:48:05	1.40.4.3
+++ krb524/krb524d.c	2002/10/15 23:32:45
@@ -70,6 +70,7 @@
 void *handle;
 
 int use_keytab, use_master;
+int allow_v4_crossrealm = 0;
 char *keytab = NULL;
 krb5_keytab kt;
 
@@ -134,7 +135,10 @@
      config_params.mask = 0;
      
      while (argc) {
-	  if (strncmp(*argv, "-k", 2) == 0)
+       if (strncmp(*argv, "-X", 2) == 0) {
+	 allow_v4_crossrealm = 1;
+       }
+       else if (strncmp(*argv, "-k", 2) == 0)
 	       use_keytab = 1;
 	  else if (strncmp(*argv, "-m", 2) == 0)
 	       use_master = 1;
@@ -317,7 +317,7 @@
      if (debug)
 	  printf("V5 ticket decoded\n");
      
-     if( v5tkt->server->length >= 1
+     if( krb5_princ_size(context, v5tkt->server) >= 1
 	 &&krb5_princ_component(context, v5tkt->server, 0)->length == 3
 	 &&strncmp(krb5_princ_component(context, v5tkt->server, 0)->data,
 		   "afs", 3) == 0) {
@@ -495,19 +499,7 @@
 				   &v5_service_key, NULL)))
 	  goto error;
 
-     if ((ret = lookup_service_key(context, v5tkt->server,
-				   ENCTYPE_DES3_CBC_RAW,
-				   0, /* highest kvno */
-				   &v4_service_key, v4kvno)) &&
-	 (ret = lookup_service_key(context, v5tkt->server,
-				   ENCTYPE_LOCAL_DES3_HMAC_SHA1,
-				   0,
-				   &v4_service_key, v4kvno)) &&
-	 (ret = lookup_service_key(context, v5tkt->server,
-				   ENCTYPE_DES3_CBC_SHA1,
-				   0,
-				   &v4_service_key, v4kvno)) &&
-	 (ret = lookup_service_key(context, v5tkt->server,
+     if ( (ret = lookup_service_key(context, v5tkt->server,
 				   ENCTYPE_DES_CBC_CRC,
 				   0,
 				   &v4_service_key, v4kvno)))
@@ -515,8 +507,19 @@
 
      if (debug)
 	  printf("service key retrieved\n");
+     if ((ret = krb5_decrypt_tkt_part(context, &v5_service_key, v5tkt))) {
+       goto error;
+     }
 
-     ret = krb524_convert_tkt_skey(context, v5tkt, &v4tkt, &v5_service_key,
+    if (!(allow_v4_crossrealm || krb5_realm_compare(context, v5tkt->server,
+						    v5tkt->enc_part2->client))) {
+ret =  KRB5KDC_ERR_POLICY ;
+ goto error;
+    }
+    krb5_free_enc_tkt_part(context, v5tkt->enc_part2);
+    v5tkt->enc_part2= NULL;
+
+         ret = krb524_convert_tkt_skey(context, v5tkt, &v4tkt, &v5_service_key,
 				   &v4_service_key,
 				   (struct sockaddr_in *)saddr);
      if (ret)
@@ -532,6 +535,9 @@
 	  printf("v4 credentials encoded\n");
 
  error:
+     if (v5tkt->enc_part2)
+	 krb5_free_enc_tkt_part(context, v5tkt->enc_part2);
+
      if(v5_service_key.contents)
        krb5_free_keyblock_contents(context, &v5_service_key);
      if (v4_service_key.contents)
diff -ur krb5-1.2.7/src/krb524/krb524d.c krb5-1.2.7/src/krb524/krb524d.c
