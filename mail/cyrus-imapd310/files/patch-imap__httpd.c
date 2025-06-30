--- imap/httpd.c.orig	2025-06-27 04:15:42 UTC
+++ imap/httpd.c
@@ -1286,7 +1286,22 @@ static int tls_init(int client_auth, struct buf *serve
 
 static int tls_init(int client_auth, struct buf *serverinfo)
 {
+#ifdef OPENSSL_FULL_VERSION_STR
     buf_printf(serverinfo, " OpenSSL/%s", OPENSSL_FULL_VERSION_STR);
+#else
+    unsigned long version = OPENSSL_VERSION_NUMBER;
+    unsigned int status   = version & 0x0f; version >>= 4;
+    unsigned int patch    = version & 0xff; version >>= 8;
+    unsigned int fix      = version & 0xff; version >>= 8;
+    unsigned int minor    = version & 0xff; version >>= 8;
+    unsigned int major    = version & 0xff;
+
+    buf_printf(serverinfo, " OpenSSL/%u.%u.%u", major, minor, fix);
+
+    if (status == 0) buf_appendcstr(serverinfo, "-dev");
+    else if (status < 15) buf_printf(serverinfo, "-beta%u", status);
+    else if (patch) buf_putc(serverinfo, patch + 'a' - 1);
+#endif
 
     if (!tls_enabled()) return HTTP_UNAVAILABLE;
 
