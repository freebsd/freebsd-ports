--- pxyconn.c.orig	2024-03-15 21:14:16 UTC
+++ pxyconn.c
@@ -72,6 +72,10 @@ bufferevent_openssl_set_allow_dirty_shutdown(UNUSED st
 }
 #endif /* LIBEVENT_VERSION_NUMBER < 0x02010000 */
 
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+#define ERR_GET_FUNC(x) 0
+#define ERR_func_error_string(x) ""
+#endif
 
 /*
  * Maximum size of data to buffer per connection direction before
@@ -586,7 +590,7 @@ out:
  * keep a pointer to the object (which we never do here).
  */
 #ifdef HAVE_SSLV2
-#define MAYBE_UNUSED 
+#define MAYBE_UNUSED
 #else /* !HAVE_SSLV2 */
 #define MAYBE_UNUSED UNUSED
 #endif /* !HAVE_SSLV2 */
@@ -2428,7 +2432,7 @@ pxy_sni_resolve_cb(int errcode, struct evutil_addrinfo
  * after the first ssl callout failed because of client cert auth.
  */
 #ifndef OPENSSL_NO_TLSEXT
-#define MAYBE_UNUSED 
+#define MAYBE_UNUSED
 #else /* OPENSSL_NO_TLSEXT */
 #define MAYBE_UNUSED UNUSED
 #endif /* OPENSSL_NO_TLSEXT */
