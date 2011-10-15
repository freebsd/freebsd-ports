--- ./memdb.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./memdb.c	2011-10-14 22:36:47.000000000 -0400
@@ -170,7 +170,9 @@
 	asprintf(&env[ei++], "THRESHOLD_COUNT=%d", bucket->count + bucket->excess);
 	env[ei] = NULL;	
 	assert(ei < MAX_ENV);
+#ifdef __Linux__
 	run_trigger(bc->trigger, NULL, env);
+#endif
 	for (i = 0; i < ei; i++)
 		free(env[i]);
 out:
