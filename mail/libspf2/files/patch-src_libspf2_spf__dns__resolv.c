Index: src/libspf2/spf_dns_resolv.c
diff -u -p src/libspf2/spf_dns_resolv.c.orig src/libspf2/spf_dns_resolv.c
--- src/libspf2/spf_dns_resolv.c.orig	Thu Oct 16 07:02:03 2008
+++ src/libspf2/spf_dns_resolv.c	Fri Oct 24 12:19:29 2008
@@ -92,7 +92,11 @@ static pthread_key_t	res_state_key;
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
 
@@ -615,7 +619,7 @@ SPF_dns_resolv_new(SPF_dns_server_t *lay
 #if HAVE_DECL_RES_NINIT
 	pthread_once(&res_state_control, SPF_dns_resolv_init_key);
 #else
-	if ( res_init() != 0 ) {
+	if ((_res.options & RES_INIT) == 0 && res_init() != 0) {
 		perror("res_init");
 		return NULL;
 	}
