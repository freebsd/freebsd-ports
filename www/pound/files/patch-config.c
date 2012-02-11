--- ./config.c.orig	2010-02-02 11:49:02.000000000 +0000
+++ ./config.c	2012-02-11 22:51:28.219835635 +0000
@@ -431,14 +431,22 @@
         res = (res ^ *k++) * 16777619;
     return res;
 }
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+static IMPLEMENT_LHASH_HASH_FN(t, TABNODE)
+#else
 static IMPLEMENT_LHASH_HASH_FN(t_hash, const TABNODE *)
+#endif
 
 static int
 t_cmp(const TABNODE *d1, const TABNODE *d2)
 {
     return strcmp(d1->key, d2->key);
 }
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+static IMPLEMENT_LHASH_COMP_FN(t, TABNODE)
+#else
 static IMPLEMENT_LHASH_COMP_FN(t_cmp, const TABNODE *)
+#endif
 
 /*
  * parse a service
@@ -460,7 +468,11 @@
     pthread_mutex_init(&res->mut, NULL);
     if(svc_name)
         strncpy(res->name, svc_name, KEY_SIZE);
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    if((res->sessions = LHM_lh_new(TABNODE, t)) == NULL)
+#else
     if((res->sessions = lh_new(LHASH_HASH_FN(t_hash), LHASH_COMP_FN(t_cmp))) == NULL)
+#endif
         conf_err("lh_new failed - aborted");
     ign_case = ignore_case;
     while(conf_fgets(lin, MAXBUF)) {
