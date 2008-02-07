--- include/asterisk/features.h.orig	Thu Aug 23 23:16:41 2007
+++ include/asterisk/features.h	Tue Dec 11 17:13:52 2007
@@ -31,6 +31,20 @@
 #define FEATURE_EXTEN_LEN	32
 #define FEATURE_MOH_LEN		80  /* same as MAX_MUSICCLASS from channel.h */
 
+#define FEATURE_RETURN_HANGUP		-1
+#define FEATURE_RETURN_SUCCESSBREAK	 0
+#define FEATURE_RETURN_PBX_KEEPALIVE	AST_PBX_KEEPALIVE
+#define FEATURE_RETURN_NO_HANGUP_PEER	AST_PBX_NO_HANGUP_PEER
+#define FEATURE_RETURN_PASSDIGITS	 21
+#define FEATURE_RETURN_STOREDIGITS	 22
+#define FEATURE_RETURN_SUCCESS	 	 23
+#define FEATURE_RETURN_KEEPTRYING    24
+
+#define FEATURE_SENSE_CHAN	(1 << 0)
+#define FEATURE_SENSE_PEER	(1 << 1)
+
+typedef int (*feature_operation)(struct ast_channel *chan, struct ast_channel *peer, struct ast_bridge_config *config, char *code, int sense, void *data);
+
 /*! \brief main call feature structure */
 struct ast_call_feature {
 	int feature_mask;
@@ -38,7 +52,7 @@
 	char sname[FEATURE_SNAME_LEN];
 	char exten[FEATURE_MAX_LEN];
 	char default_exten[FEATURE_MAX_LEN];
-	int (*operation)(struct ast_channel *chan, struct ast_channel *peer, struct ast_bridge_config *config, char *code, int sense, void *data);
+	feature_operation operation;
 	unsigned int flags;
 	char app[FEATURE_APP_LEN];		
 	char app_args[FEATURE_APP_ARGS_LEN];
@@ -47,6 +61,12 @@
 };
 
 
+struct feature_interpret_result {
+    struct ast_call_feature *builtin_feature;
+    struct ast_call_feature *dynamic_features[20];
+    int num_dyn_features;
+};
+
 
 /*! \brief Park a call and read back parked location 
  *  \param chan the channel to actually be parked
@@ -93,5 +113,11 @@
 /*! \brief unregister feature from feature_set
     \param feature the ast_call_feature object which was registered before*/
 void ast_unregister_feature(struct ast_call_feature *feature);
+
+int ast_feature_detect(struct ast_channel *chan, const struct ast_flags *features, char *code, struct feature_interpret_result *result);
+
+void ast_features_lock(void);
+void ast_features_unlock(void);
+
 
 #endif /* _AST_FEATURES_H */
