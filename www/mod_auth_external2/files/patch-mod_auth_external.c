--- mod_auth_external.c.orig	2006-02-15 22:44:53 UTC
+++ mod_auth_external.c
@@ -500,8 +500,13 @@
 	if (remote_host != NULL)
 	    child_env[i++]= apr_pstrcat(r->pool, ENV_HOST"=", remote_host, NULL);
 
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20111130
+	if (c->client_ip)
+	    child_env[i++]= apr_pstrcat(r->pool, ENV_IP"=", c->client_ip, NULL);
+#else
 	if (c->remote_ip)
 	    child_env[i++]= apr_pstrcat(r->pool, ENV_IP"=", c->remote_ip, NULL);
+#endif
 
 	if (r->uri)
 	    child_env[i++]= apr_pstrcat(r->pool, ENV_URI"=", r->uri, NULL);
