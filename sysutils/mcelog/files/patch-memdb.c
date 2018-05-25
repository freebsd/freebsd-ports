--- memdb.c.orig	2018-05-22 17:06:36 UTC
+++ memdb.c
@@ -172,7 +172,9 @@ void memdb_trigger(char *msg, struct memdimm *md,  tim
 	xasprintf(&env[ei++], "THRESHOLD_COUNT=%d", bucket->count);
 	env[ei] = NULL;	
 	assert(ei < MAX_ENV);
+#ifdef __Linux__
 	run_trigger(bc->trigger, args, env, sync);
+#endif
 	for (i = 0; i < ei; i++)
 		free(env[i]);
 out:
