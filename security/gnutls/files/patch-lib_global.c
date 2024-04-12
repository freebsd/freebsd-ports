--- lib/global.c.orig	2024-04-11 15:36:24 UTC
+++ lib/global.c
@@ -29,6 +29,13 @@
 #include "random.h"
 #include <gnutls/pkcs11.h>
 
+#if __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version >= 1400094
+#include <dlfcn.h>
+#endif
+#endif
+
 #include "hello_ext.h" /* for _gnutls_hello_ext_init */
 #include "supplemental.h" /* for _gnutls_supplemental_deinit */
 #include "locks.h"
@@ -520,6 +527,26 @@ static void _CONSTRUCTOR lib_init(void)
 		if (ret == 1)
 			return;
 	}
+
+#if __FreeBSD__
+#if __FreeBSD_version >= 1400094
+	/* This dlopen call initialises libpthread if it is present.  Normally
+	   this is handled by linking to libpthread but libgnutls does not link
+	   with libpthread to avoid the overhead for non-threaded programs.  */
+	(void) dlopen("libpthread.so", RTLD_LAZY | RTLD_GLOBAL | RTLD_NOLOAD);
+#else
+	/* The dlopen call above does not work correctly on older versions of
+	   FreeBSD.  Call pthread_mutex_timedlock instead.  It initialises
+	   libpthread and there's no libc stub that can preempt it.  */
+#pragma weak pthread_mutex_timedlock
+	if (pthread_mutex_timedlock != NULL) {
+		pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
+		pthread_mutex_timedlock(&lock, NULL);
+		pthread_mutex_unlock(&lock);
+		pthread_mutex_destroy(&lock);
+	}
+#endif
+#endif
 
 	ret = _gnutls_global_init(1);
 	if (ret < 0) {
