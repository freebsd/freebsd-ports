--- res/res_features.c.orig	Wed Feb  6 16:55:29 2008
+++ res/res_features.c	Wed Feb  6 17:02:00 2008
@@ -477,18 +477,6 @@ int ast_masq_park_call(struct ast_channe
 }
 
 
-#define FEATURE_RETURN_HANGUP		-1
-#define FEATURE_RETURN_SUCCESSBREAK	 0
-#define FEATURE_RETURN_PBX_KEEPALIVE	AST_PBX_KEEPALIVE
-#define FEATURE_RETURN_NO_HANGUP_PEER	AST_PBX_NO_HANGUP_PEER
-#define FEATURE_RETURN_PASSDIGITS	 21
-#define FEATURE_RETURN_STOREDIGITS	 22
-#define FEATURE_RETURN_SUCCESS	 	 23
-#define FEATURE_RETURN_KEEPTRYING    24
-
-#define FEATURE_SENSE_CHAN	(1 << 0)
-#define FEATURE_SENSE_PEER	(1 << 1)
-
 /*! \brief
  * set caller and callee according to the direction
  */
@@ -1052,32 +1040,35 @@ static int remap_feature(const char *nam
 	return res;
 }
 
-static int ast_feature_interpret(struct ast_channel *chan, struct ast_channel *peer, struct ast_bridge_config *config, char *code, int sense)
+void ast_features_lock(void)
+{
+	ast_rwlock_rdlock(&features_lock);
+	AST_LIST_LOCK(&feature_list);
+}
+
+void ast_features_unlock(void)
+{
+	AST_LIST_UNLOCK(&feature_list);
+	ast_rwlock_unlock(&features_lock);
+}
+
+int ast_feature_detect(struct ast_channel *chan, const struct ast_flags *features, char *code, struct feature_interpret_result *result)
 {
 	int x;
-	struct ast_flags features;
 	int res = FEATURE_RETURN_PASSDIGITS;
 	struct ast_call_feature *feature;
-	const char *dynamic_features;
+	const char *dynamic_features = pbx_builtin_getvar_helper(chan, "DYNAMIC_FEATURES");
 	char *tmp, *tok;
 
-	if (sense == FEATURE_SENSE_CHAN) {
-		ast_copy_flags(&features, &(config->features_caller), AST_FLAGS_ALL);	
-		dynamic_features = pbx_builtin_getvar_helper(chan, "DYNAMIC_FEATURES");
-	} else {
-		ast_copy_flags(&features, &(config->features_callee), AST_FLAGS_ALL);	
-		dynamic_features = pbx_builtin_getvar_helper(peer, "DYNAMIC_FEATURES");
-	}
-	if (option_debug > 2)
-		ast_log(LOG_DEBUG, "Feature interpret: chan=%s, peer=%s, sense=%d, features=%d dynamic=%s\n", chan->name, peer->name, sense, features.flags, dynamic_features);
+	result->builtin_feature = NULL;
+	result->num_dyn_features = 0;
 
-	ast_rwlock_rdlock(&features_lock);
 	for (x = 0; x < FEATURES_COUNT; x++) {
-		if ((ast_test_flag(&features, builtin_features[x].feature_mask)) &&
+		if ((ast_test_flag(features, builtin_features[x].feature_mask)) &&
 		    !ast_strlen_zero(builtin_features[x].exten)) {
 			/* Feature is up for consideration */
 			if (!strcmp(builtin_features[x].exten, code)) {
-				res = builtin_features[x].operation(chan, peer, config, code, sense, NULL);
+				result->builtin_feature = &builtin_features[x];
 				break;
 			} else if (!strncmp(builtin_features[x].exten, code, strlen(code))) {
 				if (res == FEATURE_RETURN_PASSDIGITS)
@@ -1085,7 +1076,6 @@ static int ast_feature_interpret(struct 
 			}
 		}
 	}
-	ast_rwlock_unlock(&features_lock);
 
 	if (ast_strlen_zero(dynamic_features))
 		return res;
@@ -1093,9 +1083,7 @@ static int ast_feature_interpret(struct 
 	tmp = ast_strdupa(dynamic_features);
 
 	while ((tok = strsep(&tmp, "#"))) {
-		AST_LIST_LOCK(&feature_list);	
 		if (!(feature = find_dynamic_feature(tok))) {
-			AST_LIST_UNLOCK(&feature_list);
 			continue;
 		}
 			
@@ -1103,18 +1091,49 @@ static int ast_feature_interpret(struct 
 		if (!strcmp(feature->exten, code)) {
 			if (option_verbose > 2)
 				ast_verbose(VERBOSE_PREFIX_3 " Feature Found: %s exten: %s\n",feature->sname, tok);
-			res = feature->operation(chan, peer, config, code, sense, feature);
-			if (res != FEATURE_RETURN_KEEPTRYING) {
-				AST_LIST_UNLOCK(&feature_list);
+			result->dynamic_features[result->num_dyn_features++] = feature;
+			if (result->num_dyn_features >= (sizeof(result->dynamic_features) / sizeof(result->dynamic_features[0]))) {
 				break;
 			}
 			res = FEATURE_RETURN_PASSDIGITS;
 		} else if (!strncmp(feature->exten, code, strlen(code)))
 			res = FEATURE_RETURN_STOREDIGITS;
 
-		AST_LIST_UNLOCK(&feature_list);
 	}
 	
+	return res;
+}
+
+static int ast_feature_interpret(struct ast_channel *chan, struct ast_channel *peer, struct ast_bridge_config *config, char *code, int sense)
+{
+	struct feature_interpret_result result;
+	int x;
+	struct ast_flags features;
+	int res = FEATURE_RETURN_PASSDIGITS;
+	struct ast_call_feature *feature;
+
+	if (sense == FEATURE_SENSE_CHAN)
+		ast_copy_flags(&features, &(config->features_caller), AST_FLAGS_ALL);	
+	else
+		ast_copy_flags(&features, &(config->features_callee), AST_FLAGS_ALL);	
+	if (option_debug > 2)
+		ast_log(LOG_DEBUG, "Feature interpret: chan=%s, peer=%s, sense=%d, features=%d\n", chan->name, peer->name, sense, features.flags);
+
+	ast_features_lock();
+	res = ast_feature_detect(chan, &features, code, &result);
+
+	if (result.builtin_feature)
+		res = result.builtin_feature->operation(chan, peer, config, code, sense, NULL);
+
+	for (x = 0; x < result.num_dyn_features; ++x) {
+		feature = result.dynamic_features[x];
+		res = feature->operation(chan, peer, config, code, sense, feature);
+		if (res != FEATURE_RETURN_KEEPTRYING)
+			break;
+		res = FEATURE_RETURN_PASSDIGITS;
+	}
+
+	ast_features_unlock();
 	return res;
 }
 
