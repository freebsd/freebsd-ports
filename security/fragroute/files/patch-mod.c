--- mod.c.orig	2020-03-22 06:34:47 UTC
+++ mod.c
@@ -151,7 +151,7 @@ mod_close(void)
 {
 	struct rule *rule;
 	
-	TAILQ_FOREACH_REVERSE(rule, &rules, next, head) {
+	TAILQ_FOREACH_REVERSE(rule, &rules, head, next) {
 		if (rule->mod->close != NULL)
 			rule->data = rule->mod->close(rule->data);
 		TAILQ_REMOVE(&rules, rule, next);
