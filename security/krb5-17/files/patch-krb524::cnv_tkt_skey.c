Index: krb524/cnv_tkt_skey.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/krb524/cnv_tkt_skey.c,v
retrieving revision 1.17.2.1.2.1
diff -u -r1.17.2.1.2.1 cnv_tkt_skey.c
--- krb524/cnv_tkt_skey.c	2002/03/01 16:05:20	1.17.2.1.2.1
+++ krb524/cnv_tkt_skey.c	2002/10/15 23:32:45
@@ -173,25 +173,7 @@
 				 sname,
 				 sinst,
 				 v4_skey->contents);
-     } else {
-	 /* Force enctype to be raw if using DES3. */
-	 if (v4_skey->enctype == ENCTYPE_DES3_CBC_SHA1 ||
-	     v4_skey->enctype == ENCTYPE_LOCAL_DES3_HMAC_SHA1)
-	     v4_skey->enctype = ENCTYPE_DES3_CBC_RAW;
-	 ret = krb_cr_tkt_krb5(v4tkt,
-			       0, /* flags */			     
-			       pname,
-			       pinst,
-			       prealm,
-			       *((unsigned long *)kaddr.contents),
-			       (char *) v5etkt->session->contents,
-			       lifetime,
-			       /* issue_data */
-			       server_time,
-			       sname,
-			       sinst,
-			       v4_skey);
-     }
+     } else  abort();
 
      krb5_free_enc_tkt_part(context, v5etkt);
      v5tkt->enc_part2 = NULL;
