Description: Build on older OpenSSL versions without some options.
Forwarded: https://stunnel.mirt.net/cgi-bin/bugzilla3/show_bug.cgi?id=3
Author: Michal Trojnara <Michal.Trojnara@mirt.net>
	Peter Pentchev <roam@ringlet.net>
Last-Update: 2009-11-19

--- src/options.c.orig
+++ src/options.c
@@ -1136,7 +1136,9 @@
         if(strcasecmp(opt, "sessiond"))
             break;
         section->option.sessiond=1;
+#ifdef SSL_OP_NO_TICKET
         section->ssl_options|=SSL_OP_NO_TICKET;
+#endif
         if(!name2addrlist(&section->sessiond_addr, arg, DEFAULT_LOOPBACK))
             return "Failed to resolve sessiond server address";
         return NULL; /* OK */
@@ -1704,15 +1706,23 @@
         {"TLS_D5_BUG", SSL_OP_TLS_D5_BUG},
         {"TLS_BLOCK_PADDING_BUG", SSL_OP_TLS_BLOCK_PADDING_BUG},
         {"DONT_INSERT_EMPTY_FRAGMENTS", SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS},
+#ifdef SSL_OP_NO_QUERY_MTU
         {"NO_QUERY_MTU", SSL_OP_NO_QUERY_MTU},
+#endif
+#ifdef SSL_OP_COOKIE_EXCHANGE
         {"COOKIE_EXCHANGE", SSL_OP_COOKIE_EXCHANGE},
+#endif
+#ifdef SSL_OP_NO_TICKET
         {"NO_TICKET", SSL_OP_NO_TICKET},
+#endif
         {"NO_SESSION_RESUMPTION_ON_RENEGOTIATION",
             SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION},
 #ifdef SSL_OP_NO_COMPRESSION
         {"NO_COMPRESSION", SSL_OP_NO_COMPRESSION},
 #endif
+#ifdef SSL_OP_SINGLE_ECDH_USE
         {"SINGLE_ECDH_USE", SSL_OP_SINGLE_ECDH_USE},
+#endif
         {"SINGLE_DH_USE", SSL_OP_SINGLE_DH_USE},
         {"EPHEMERAL_RSA", SSL_OP_EPHEMERAL_RSA},
         {"CIPHER_SERVER_PREFERENCE", SSL_OP_CIPHER_SERVER_PREFERENCE},
