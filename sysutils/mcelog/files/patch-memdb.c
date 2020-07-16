--- memdb.c.orig	2020-07-16 03:44:57 UTC
+++ memdb.c
@@ -173,7 +173,9 @@ void memdb_trigger(char *msg, struct memdimm *md,  tim
 	xasprintf(&env[ei++], "THRESHOLD_COUNT=%d", bucket->count);
 	env[ei] = NULL;	
 	assert(ei < MAX_ENV);
+#ifdef __Linux__
 	run_trigger(bc->trigger, args, env, sync, reporter);
+#endif
 	for (i = 0; i < ei; i++)
 		free(env[i]);
 out:
