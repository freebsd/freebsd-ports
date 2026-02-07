--- hndlrs.c.orig	2005-07-17 19:55:13.000000000 -0500
+++ hndlrs.c	2015-01-21 14:47:27.000000000 -0600
@@ -466,7 +466,11 @@
 						if(gMtaHostIpfw)
 							mlfi_MtaHostIpfwAction(priv->ipstr,"add");
 					}
-					else if(gMtaHostChk && !priv->islocalnethost && !dns_query_rr_a(priv->statp,priv->helo))
+					else if(gMtaHostChk
+						&& !priv->islocalnethost
+						&& !dns_query_rr_a(priv->statp,priv->helo)
+						&& !dns_query_rr_aaaa(priv->statp,priv->helo)
+						)
 					{
 						mlfi_setreply(ctx,550,"5.7.1","Rejecting due to security policy - Invalid hostname '%s', Please see: %s#invalidhostname",priv->helo,gPolicyUrl);
 						mlfi_debug("envrcpt: Invalid MTA hostname '%s'\n",priv->helo);
