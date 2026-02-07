Fix crash on close if there is no ctx.

--- src/auth-ldap.m.orig	2018-07-26 20:17:21 UTC
+++ src/auth-ldap.m
@@ -247,6 +247,9 @@ OPENVPN_EXPORT void
 {
     ldap_ctx *ctx = handle;
 
+    if (!ctx)
+        return;
+
     /* Clean up the configuration file */
     [ctx->config release];
 
@@ -545,7 +548,6 @@ openvpn_plugin_func_v1(openvpn_plugin_ha
     pool = [[TRAutoreleasePool alloc] init];
 
     username = get_env("username", envp);
-    TRString *userName=[[TRString alloc]initWithCString: username];
     password = get_env("password", envp);
     remoteAddress = get_env("ifconfig_pool_remote_ip", envp);
 
@@ -556,6 +558,8 @@ openvpn_plugin_func_v1(openvpn_plugin_ha
         goto cleanup;
     }
 
+    TRString *userName=[[TRString alloc]initWithCString: username];
+
     /* Create an LDAP connection */
     if (!(ldap = connect_ldap(ctx->config))) {
         [TRLog error: "LDAP connect failed."];
