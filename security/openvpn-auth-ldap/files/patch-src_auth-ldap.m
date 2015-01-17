Fix crash on close if there is no ctx.

--- src/auth-ldap.m.orig	2012-08-15 13:55:46 UTC
+++ src/auth-ldap.m
@@ -245,6 +245,9 @@ OPENVPN_EXPORT void
 {
     ldap_ctx *ctx = handle;
 
+    if (!ctx)
+        return;
+
     /* Clean up the configuration file */
     [ctx->config release];
 
