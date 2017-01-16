--- lib/random.c.orig	2017-01-08 09:27:28 UTC
+++ lib/random.c
@@ -33,24 +33,24 @@ void *gnutls_rnd_ctx;
 GNUTLS_STATIC_MUTEX(gnutls_rnd_init_mutex);
 
 #ifdef HAVE_STDATOMIC_H
-static atomic_uint rnd_initialized = 0;
+static atomic_uint rnd_initialized = ATOMIC_VAR_INIT(0);
 
 inline static int _gnutls_rnd_init(void)
 {
-	if (unlikely(!rnd_initialized)) {
+	if (unlikely(!atomic_load(&rnd_initialized))) {
 		if (_gnutls_rnd_ops.init == NULL) {
-			rnd_initialized = 1;
+			atomic_store(&rnd_initialized, 1);
 			return 0;
 		}
 
 		GNUTLS_STATIC_MUTEX_LOCK(gnutls_rnd_init_mutex);
-		if (!rnd_initialized) {
+		if (!atomic_load(&rnd_initialized)) {
 			if (_gnutls_rnd_ops.init(&gnutls_rnd_ctx) < 0) {
 				gnutls_assert();
 				GNUTLS_STATIC_MUTEX_UNLOCK(gnutls_rnd_init_mutex);
 				return GNUTLS_E_RANDOM_FAILED;
 			}
-			rnd_initialized = 1;
+			atomic_store(&rnd_initialized, 1);
 		}
 		GNUTLS_STATIC_MUTEX_UNLOCK(gnutls_rnd_init_mutex);
 	}
@@ -107,10 +107,10 @@ int _gnutls_rnd_preinit(void)
 
 void _gnutls_rnd_deinit(void)
 {
-	if (rnd_initialized && _gnutls_rnd_ops.deinit != NULL) {
+	if (atomic_load(&rnd_initialized) && _gnutls_rnd_ops.deinit != NULL) {
 		_gnutls_rnd_ops.deinit(gnutls_rnd_ctx);
 	}
-	rnd_initialized = 0;
+	atomic_store(&rnd_initialized, 0);
 
 	_rnd_system_entropy_deinit();
 
@@ -162,6 +162,6 @@ int gnutls_rnd(gnutls_rnd_level_t level,
  **/
 void gnutls_rnd_refresh(void)
 {
-	if (rnd_initialized && _gnutls_rnd_ops.rnd_refresh)
+	if (atomic_load(&rnd_initialized) && _gnutls_rnd_ops.rnd_refresh)
 		_gnutls_rnd_ops.rnd_refresh(gnutls_rnd_ctx);
 }
