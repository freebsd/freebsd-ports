--- src/libspf2/spf_dns_resolv.c.orig	Wed Mar  2 22:59:01 2005
+++ src/libspf2/spf_dns_resolv.c	Wed Mar  2 23:01:06 2005
@@ -77,7 +77,9 @@
 static void
 SPF_dns_resolv_thread_term(void *arg)
 {
+#if HAVE_DECL_RES_NINIT
 	res_nclose( (struct __res_state *)arg );
+#endif
 	free(arg);
 }
 
@@ -144,9 +146,15 @@
 	if (res_spec == NULL) {
 		res_state = (struct __res_state *)
 						malloc(sizeof(struct __res_state));
+#if HAVE_DECL_RES_NINIT
 		if (res_ninit(res_state) != 0) {
 			SPF_error("Failed to call res_ninit()");
 		}
+#else
+		if (res_init() != 0) {
+			SPF_error("Failed to call res_init()");
+		}
+#endif
 		pthread_setspecific(res_state_key, (void *)res_state);
 	}
 	else {
