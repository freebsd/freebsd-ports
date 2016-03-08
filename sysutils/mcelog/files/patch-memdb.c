--- memdb.c.orig	2016-02-10 18:38:43 UTC
+++ memdb.c
@@ -172,7 +172,9 @@ void memdb_trigger(char *msg, struct mem
 	asprintf(&env[ei++], "THRESHOLD_COUNT=%d", bucket->count);
 	env[ei] = NULL;	
 	assert(ei < MAX_ENV);
+#ifdef __Linux__
 	run_trigger(bc->trigger, NULL, env);
+#endif
 	for (i = 0; i < ei; i++)
 		free(env[i]);
 out:
