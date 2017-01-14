--- src/lib-sieve/sieve-result.c.orig	2016-10-20 22:48:08 UTC
+++ src/lib-sieve/sieve-result.c
@@ -928,7 +928,7 @@ static int _sieve_result_implicit_keep
 (struct sieve_result *result, bool rollback)
 {
 	const struct sieve_action_exec_env *aenv = &result->action_env;
-	struct sieve_result_action *rac;
+	struct sieve_result_action *rac, *kac;
 	int status = SIEVE_EXEC_OK;
 	struct sieve_result_side_effect *rsef, *rsef_first = NULL;
 	void *tr_context = NULL;
@@ -937,38 +937,54 @@ static int _sieve_result_implicit_keep
 	if ( (aenv->flags & SIEVE_EXECUTE_FLAG_DEFER_KEEP) != 0 )
 		return SIEVE_EXEC_OK;
 
-	if ( rollback ) {
+	if ( rollback )
 		act_keep = result->failure_action;
-		act_keep.mail = NULL;
-	} else {
+	else
 		act_keep = result->keep_action;
-		act_keep.mail = sieve_message_get_mail(aenv->msgctx);
-	}
+	act_keep.mail = NULL;
 
 	/* If keep is a non-action, return right away */
 	if ( act_keep.def == NULL )
 		return SIEVE_EXEC_OK;
 
-	/* Scan for execution of keep-equal actions */
-	rac = result->first_action;
-	while ( rac != NULL ) {
-		if ( rac->action.def == act_keep.def && act_keep.def->equals != NULL &&
-			act_keep.def->equals(aenv->scriptenv, NULL, &rac->action) &&
-			rac->action.executed )
-			return SIEVE_EXEC_OK;
-
-		rac = rac->next;
+	/* Scan for deferred keep */
+	kac = result->last_action;
+	while ( kac != NULL && kac->action.executed ) {
+		if ( kac->keep && kac->action.def == NULL )
+			break;
+		kac = kac->prev;
 	}
 
-	/* Apply any implicit side effects if applicable */
-	if ( !rollback && hash_table_is_created(result->action_contexts) ) {
-		struct sieve_result_action_context *actctx;
+	if (kac == NULL) {
+		if ( !rollback )
+			act_keep.mail = sieve_message_get_mail(aenv->msgctx);
 
-		/* Check for implicit side effects to keep action */
-		actctx = hash_table_lookup(result->action_contexts, act_keep.def);
+		/* Scan for execution of keep-equal actions */
+		rac = result->first_action;
+		while ( rac != NULL ) {
+			if ( rac->action.def == act_keep.def && act_keep.def->equals != NULL &&
+				act_keep.def->equals(aenv->scriptenv, NULL, &rac->action) &&
+				rac->action.executed )
+				return SIEVE_EXEC_OK;
 
-		if ( actctx != NULL && actctx->seffects != NULL )
-			rsef_first = actctx->seffects->first_effect;
+			rac = rac->next;
+		}
+
+		/* Apply any implicit side effects if applicable */
+		if ( !rollback && hash_table_is_created(result->action_contexts) ) {
+			struct sieve_result_action_context *actctx;
+
+			/* Check for implicit side effects to keep action */
+			actctx = hash_table_lookup(result->action_contexts, act_keep.def);
+
+			if ( actctx != NULL && actctx->seffects != NULL )
+				rsef_first = actctx->seffects->first_effect;
+		}
+	} else if ( !rollback ) {
+		act_keep.location = kac->action.location;
+		act_keep.mail = kac->action.mail;
+		if ( kac->seffects != NULL )
+			rsef_first = kac->seffects->first_effect;
 	}
 
 	/* Start keep action */
