Index: src/libspf2/spf_dns_resolv.c
diff -u -p src/libspf2/spf_dns_resolv.c.orig src/libspf2/spf_dns_resolv.c
--- src/libspf2/spf_dns_resolv.c.orig	Sat Feb 19 11:38:12 2005
+++ src/libspf2/spf_dns_resolv.c	Mon Jul 31 14:02:57 2006
@@ -71,13 +71,18 @@ typedef struct
 # define SPF_h_errno h_errno
 #endif
 
+#if HAVE_DECL_RES_NINIT
 static pthread_once_t	res_state_control = PTHREAD_ONCE_INIT;
 static pthread_key_t	res_state_key;
 
 static void
 SPF_dns_resolv_thread_term(void *arg)
 {
+#ifdef res_ndestroy
+	res_ndestroy( (struct __res_state *)arg );
+#else
 	res_nclose( (struct __res_state *)arg );
+#endif
 	free(arg);
 }
 
@@ -86,6 +91,7 @@ SPF_dns_resolv_init_key()
 {
 	pthread_key_create(&res_state_key, SPF_dns_resolv_thread_term);
 }
+#endif
 
 
 #if 0
@@ -130,8 +136,10 @@ SPF_dns_resolv_lookup(SPF_dns_server_t *
     int		rdlen;
     const u_char	*rdata, *rdata_end;
 
+#if HAVE_DECL_RES_NINIT
 	void				*res_spec;
 	struct __res_state	*res_state;
+#endif
 
 	SPF_ASSERT_NOTNULL(spf_dns_server);
 
@@ -140,10 +148,15 @@ SPF_dns_resolv_lookup(SPF_dns_server_t *
 	SPF_ASSERT_NOTNULL(spfhook);
 #endif
 
+#if HAVE_DECL_RES_NINIT
 	res_spec = pthread_getspecific(res_state_key);
 	if (res_spec == NULL) {
 		res_state = (struct __res_state *)
 						malloc(sizeof(struct __res_state));
+		if (res_state == NULL) {
+			SPF_error("Failed to call malloc()");
+		}
+		memset(res_state, 0, sizeof(*res_state));
 		if (res_ninit(res_state) != 0) {
 			SPF_error("Failed to call res_ninit()");
 		}
@@ -152,6 +165,11 @@ SPF_dns_resolv_lookup(SPF_dns_server_t *
 	else {
 		res_state = (struct __res_state *)res_spec;
 	}
+#else
+	if ((_res.options & RES_INIT) == 0 && res_init() != 0) {
+		SPF_error("Failed to call res_init()");
+	}
+#endif
 
     /*
      * try resolving the name
@@ -486,7 +504,9 @@ SPF_dns_resolv_new(SPF_dns_server_t *lay
 	SPF_dns_resolv_config_t	*spfhook;
 #endif
 
+#if HAVE_DECL_RES_NINIT
 	pthread_once(&res_state_control, SPF_dns_resolv_init_key);
+#endif
 
     spf_dns_server = malloc(sizeof(SPF_dns_server_t));
     if ( spf_dns_server == NULL )
@@ -517,19 +537,19 @@ SPF_dns_resolv_new(SPF_dns_server_t *lay
     spfhook = SPF_voidp2spfhook( spf_dns_server->hook );
 #endif
 
-#if HAVE_DECL_RES_NINIT
 #if 0
+#if HAVE_DECL_RES_NINIT
     if ( res_ninit( &spfhook->res_state ) != 0 ) {
 		free(spfhook);
 		free(spf_dns_server);
 		return NULL;
     }
-#endif
 #else
     if ( res_init() != 0 ) {
 		free( spf_dns_server );
 		return NULL;
     }
+#endif
 #endif
 
     return spf_dns_server;
