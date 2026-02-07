--- src/webpush/test-webpush-message.c.orig	2019-12-04 09:11:06 UTC
+++ src/webpush/test-webpush-message.c
@@ -334,6 +334,6 @@ int main(void)
 		NULL
 	};
 
-	env_put("TZ=UTC");
+	env_put("TZ", "UTC");
 	return test_run(test_functions);
 }
