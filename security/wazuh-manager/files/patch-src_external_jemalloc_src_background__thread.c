--- src/external/jemalloc/src/background_thread.c	2026-02-27 14:30:22.683015000 -0800
+++ src/external/jemalloc/src/background_thread.c	2026-02-27 14:30:57.134631000 -0800
@@ -841,6 +841,9 @@
 	 */
 #ifdef JEMALLOC_HAVE_DLSYM
 	pthread_create_fptr = dlsym(RTLD_NEXT, "pthread_create");
+	if (pthread_create_fptr == NULL) {
+		pthread_create_fptr = dlsym(RTLD_DEFAULT, "pthread_create");
+	}
 #else
 	pthread_create_fptr = NULL;
 #endif
