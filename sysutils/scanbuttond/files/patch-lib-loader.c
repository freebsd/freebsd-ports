--- lib/loader.c.orig	Wed Feb 15 18:00:12 2006
+++ lib/loader.c	Fri Mar 31 10:35:41 2006
@@ -27,7 +27,7 @@
 
 backend_t* load_backend(const char* filename)
 {
-	char* error;
+	const char* error;
 	void* dll_handle = dlopen(filename, RTLD_NOW|RTLD_LOCAL);
 	if (!dll_handle) {
 		syslog(LOG_ERR, "loader: failed to load \"%s\". Error message: \"%s\"",
