--- smtps/smtps.c.orig	2022-09-24 16:59:28 UTC
+++ smtps/smtps.c
@@ -2168,9 +2168,11 @@ ss_proxy_policy(sasl_conn_t *conn, void *context, cons
 	return SASL_OK;
 }
 
+typedef int (*sasl_callback_ft)(void);
+
 static sasl_callback_t sm_sasl_srvcbs[] =
 {
-	{	SASL_CB_PROXY_POLICY,	&ss_proxy_policy,	NULL	},
+	{	SASL_CB_PROXY_POLICY,	(sasl_callback_ft)&ss_proxy_policy,	NULL	},
 	{	SASL_CB_LIST_END,	NULL,		NULL	}
 };
 #endif
