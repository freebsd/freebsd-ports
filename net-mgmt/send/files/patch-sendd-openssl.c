--- sendd/openssl.c.orig	2019-02-27 16:25:45 UTC
+++ sendd/openssl.c
@@ -57,6 +57,11 @@ struct dlog_desc dbg_cryptox = {
 };
 #endif
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#define	X509_OBJECT_new(a)		calloc(1, sizeof(X509_OBJECT))
+#define	X509_OBJECT_get0_X509(a)	((a)->data.x509)
+#endif
+
 static char nbuf[1024]; /* for displaying X509_NAMEs */
 
 static pthread_mutex_t *lock_cs;
@@ -216,12 +221,17 @@ snd_have_chain(void *a)
 	X509_STORE_CTX *ctx = pkixip_get_store_ctx();
 	X509 *tx = a;
 	X509_NAME *subj, *iss;
-	X509_OBJECT obj[1];
+	X509_OBJECT *obj;
 
 	if (ctx == NULL) {
 		DBG(&dbg_snd, "pkixip_get_store() failed");
 		return (0);
 	}
+	obj = X509_OBJECT_new();
+	if (obj == NULL) {
+		DBG(&dbg_snd, "pkixip_get_store() X509_OBJECT() failed");
+		return (0);
+	}
 
 	for (;;) {
 		subj = X509_get_subject_name(tx);
@@ -234,7 +244,7 @@ snd_have_chain(void *a)
 			    X509_NAME_oneline(iss, nbuf, sizeof (nbuf)));
 			return (0);
 		}
-		tx = obj->data.x509;
+		tx = X509_OBJECT_get0_X509(obj);
 	}
 
 	return (1);
