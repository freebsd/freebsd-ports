--- apps/app_dial.c.orig	Wed Feb  6 18:45:30 2008
+++ apps/app_dial.c	Wed Feb  6 18:51:59 2008
@@ -297,6 +297,8 @@ AST_APP_OPTIONS(dial_exec_options, {
 	OPT_CALLER_HANGUP | OPT_CALLEE_TRANSFER | OPT_CALLER_TRANSFER | \
 	OPT_CALLEE_MONITOR | OPT_CALLER_MONITOR | OPT_CALLEE_PARK | OPT_CALLER_PARK))
 
+static int detect_disconnect(struct ast_channel *chan, char code);
+
 /* We define a custom "local user" structure because we
    use it not only for keeping track of what is in use but
    also for keeping track of who we're dialing. */
@@ -402,6 +404,7 @@ static struct ast_channel *wait_for_answ
 	struct ast_channel *peer = NULL;
 	/* single is set if only one destination is enabled */
 	int single = outgoing && !outgoing->next && !ast_test_flag(outgoing, OPT_MUSICBACK | OPT_RINGBACK);
+
 	
 	if (single) {
 		/* Turn off hold music, etc */
@@ -716,9 +719,9 @@ static struct ast_channel *wait_for_answ
 				}
 
 				if (ast_test_flag(peerflags, OPT_CALLER_HANGUP) && 
-						  (f->subclass == '*')) { /* hmm it it not guaranteed to be '*' anymore. */
+						  detect_disconnect(in, f->subclass)) { /* hmm it it not guaranteed to be '*' anymore. */
 					if (option_verbose > 2)
-						ast_verbose(VERBOSE_PREFIX_3 "User hit %c to disconnect call.\n", f->subclass);
+						ast_verbose(VERBOSE_PREFIX_3 "User requested call disconnect.\n");
 					*to=0;
 					ast_cdr_noanswer(in->cdr);
 					strcpy(status, "CANCEL");
@@ -776,6 +779,56 @@ static struct ast_channel *wait_for_answ
 	
 	return peer;
 }
+
+static char featurecode[FEATURE_MAX_LEN + 1] = "";
+
+static int detect_disconnect(struct ast_channel *chan, char code)
+{
+	struct feature_interpret_result result;
+	int x;
+	struct ast_flags features;
+	int res = FEATURE_RETURN_PASSDIGITS;
+	struct ast_call_feature *feature;
+	char *cptr;
+	int len;
+
+	len = strlen(featurecode);
+	if (len >= FEATURE_MAX_LEN) {
+		featurecode[0] = '\0';
+	}
+	cptr = &featurecode[strlen(featurecode)];
+	cptr[0] = code;
+	cptr[1] = '\0';
+
+	memset(&features, 0, sizeof(struct ast_flags));
+	ast_set_flag(&features, AST_FEATURE_DISCONNECT);
+
+	ast_features_lock();
+
+	res = ast_feature_detect(chan, &features, featurecode, &result);
+
+	if (res != FEATURE_RETURN_STOREDIGITS)
+		featurecode[0] = '\0';
+
+	if (result.builtin_feature && result.builtin_feature->feature_mask & AST_FEATURE_DISCONNECT) {
+		ast_features_unlock();
+		return 1;
+	}
+		
+	for (x = 0; x < result.num_dyn_features; ++x) {
+		feature = result.dynamic_features[x];
+		if (feature->feature_mask & AST_FEATURE_DISCONNECT) {
+			ast_features_unlock();
+			return 1;
+		}
+	}
+
+	ast_features_unlock();
+
+	return 0;
+}
+
+
 
 static void replace_macro_delimiter(char *s)
 {
