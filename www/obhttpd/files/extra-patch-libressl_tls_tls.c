--- tls/tls.c.orig	2021-05-10 21:00:13.463847000 +0000
+++ tls/tls.c	2021-05-10 21:02:18.217054000 +0000
@@ -57,10 +57,13 @@ tls_do_init(void)
 int
 tls_init(void)
 {
-	static pthread_once_t once = PTHREAD_ONCE_INIT;
-
-	if (pthread_once(&once, tls_do_init) != 0)
-		return -1;
+	// fail if statically-linked
+	//
+	//static pthread_once_t once = PTHREAD_ONCE_INIT;
+	//
+	//if (pthread_once(&once, tls_do_init) != 0)
+	//	return -1;
+	tls_do_init();
 
 	return tls_init_rv;
 }
