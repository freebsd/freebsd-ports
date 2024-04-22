--- lib/compress.c.orig	2024-01-23 08:52:59 UTC
+++ lib/compress.c
@@ -72,7 +72,7 @@ static int zlib_init(void)
 #ifndef _WIN32
 	if (_zlib_handle != NULL)
 		return 0;
-	if ((_zlib_handle = dlopen("libz.so.1", RTLD_NOW | RTLD_GLOBAL)) ==
+	if ((_zlib_handle = dlopen("libz.so.6", RTLD_NOW | RTLD_GLOBAL)) ==
 	    NULL)
 		goto error;
 	if ((_gnutls_zlib_compressBound =
