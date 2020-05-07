In the corner case that the global OpenSSL has an invalid command like

	MinProtocol = TLSv1.0

(Due to OpenSSL's idiosyncrasies MinProtocol = TLSv1 would be correct)

the SSL_ctx_new function leaves the errors for parsing the config file
on the stack.

OpenSSL: error:14187180:SSL routines:ssl_do_config:bad value

Since the later functions, especially the one of loading the
certificates expected a clean error this error got reported at the
wrong place.

Print the warnings with crypto_msg when we detect that we are in this
situation (this also clears the stack).
---
 src/openvpn/ssl_openssl.c | 10 ++++++++++
 1 file changed, 10 insertions(+)

Acked-by: Gert Doering <gert@greenie.muc.de>

"Explanation and Code make sense, Debian testing confirmed it fixes
the problem observed" (which was a user error in the end, but led to an 
unexpected error in openvpn).

Basic client test run with openssl 1.1.1 on Linux/Gentoo.

Your patch has been applied to the master and release/2.4 branch.

commit 75aa88af774abaa168bf72e43e1dbb57be14c044 (master)
commit 125654bfa6f99a251b581522182e85748dd8043a (release/2.4)
Author: Arne Schwabe
Date:   Tue Apr 21 12:11:22 2020 +0200

     Fix tls_ctx_client/server_new leaving error on OpenSSL error stack

     Acked-by: Gert Doering <gert@greenie.muc.de>
     Message-Id: <20200421101122.24284-1-arne@rfc2549.org>
     URL: https://www.mail-archive.com/openvpn-devel@lists.sourceforge.net/msg19802.html
     Signed-off-by: Gert Doering <gert@greenie.muc.de>

--- src/openvpn/ssl_openssl.c.orig	2020-04-16 13:26:45 UTC
+++ src/openvpn/ssl_openssl.c
@@ -110,6 +110,11 @@ tls_ctx_server_new(struct tls_root_ctx *ctx)
     {
         crypto_msg(M_FATAL, "SSL_CTX_new SSLv23_server_method");
     }
+    if (ERR_peek_error() != 0)
+    {
+        crypto_msg(M_WARN, "Warning: TLS server context initialisation "
+                   "has warnings.");
+    }
 }
 
 void
@@ -122,6 +127,11 @@ tls_ctx_client_new(struct tls_root_ctx *ctx)
     if (ctx->ctx == NULL)
     {
         crypto_msg(M_FATAL, "SSL_CTX_new SSLv23_client_method");
+    }
+    if (ERR_peek_error() != 0)
+    {
+        crypto_msg(M_WARN, "Warning: TLS client context initialisation "
+                   "has warnings.");
     }
 }
 
