diff --git a/libopendkim/tests/t-test49.c b/libopendkim/tests/t-test49.c
index e54cb37..318ad8a 100644
--- ./libopendkim/tests/t-test49.c
+++ ./libopendkim/tests/t-test49.c
@@ -53,7 +53,7 @@ main(int argc, char **argv)
 
 	int status;
 	int err;
-	u_int s1, s2, s3;
+	u_int s1, s2, s3, s4;
 	size_t buflen;
 	DB *cache;
 	char buf[BUFRSZ + 1];
@@ -99,10 +99,11 @@ main(int argc, char **argv)
 	assert(status == 1);
 
 	printf("--- retrieve cache stats\n");
-	dkim_cache_stats(&s1, &s2, &s3);
+	dkim_cache_stats(cache, &s1, &s2, &s3, &s4, FALSE);
 	assert(s1 == 3);
 	assert(s2 == 1);
 	assert(s3 == 1);
+	assert(s4 == 0);
 
 	dkim_cache_close(cache);
 #endif /* ! QUERY_CACHE */
