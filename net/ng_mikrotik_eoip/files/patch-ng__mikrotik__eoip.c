--- ng_mikrotik_eoip.c.orig	2022-09-13 07:45:40 UTC
+++ ng_mikrotik_eoip.c
@@ -193,26 +193,54 @@ static ng_fn_eachhook	check_id;
 #ifndef NO_LINEAR_HOOK_LOOKUP
 static ng_fn_eachhook	check_id;
 
+#if __FreeBSD_version >= 1400057
+struct check_id_data {
+	hook_p result;
+	uint16_t id;
+};
+#endif
+
 static int
-check_id(hook_p hook, void *id)
+check_id(hook_p hook, void *arg)
 {
 	struct tunnel_info *info = NG_HOOK_PRIVATE(hook);
+#if __FreeBSD_version >= 1400057
+	struct check_id_data *data = arg;
+#endif
+	uint16_t id;
 
-	if (info != NULL && info->id == (uint16_t)(*((unsigned int *)id)))
+#if __FreeBSD_version >= 1400057
+	id = data->id;
+#else
+	id = *((unsigned int *)arg);
+#endif
+	if (info != NULL && info->id == id) {
+#if __FreeBSD_version >= 1400057
+		data->result = hook;
+#endif
 		return 0;
-	else
+	} else
 		return 1;
 }
 
 static hook_p
 find_hook(node_p node, uint16_t id)
 {
+#if __FreeBSD_version >= 1400057
+	struct check_id_data data;
+
+	data.result = NULL;
+	data.id = id;
+	NG_NODE_FOREACH_HOOK(node, check_id, &data);
+	return data.result;
+#else
 	hook_p result = NULL;
 	unsigned int val = id;
 
 	NG_NODE_FOREACH_HOOK(node, check_id, (void*)&val, result);
 
 	return result;
+#endif
 }
 #endif /* NO_LINEAR_HOOK_LOOKUP */
 
