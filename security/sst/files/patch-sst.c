--- sst.c	2019-07-23 20:08:49.000000000 -0400
+++ sst.c	2024-01-02 21:39:44.403629000 -0500
@@ -799,5 +799,5 @@
 {
 	int im;
-	char *want = requested;
+	const char *want = requested;
 
 	struct {
@@ -828,5 +828,5 @@
 		{ "dtls", DTLS_method },
 		{ "ssl23" , SSLv23_method },
-		{ NULL, (SSL_METHOD *) NULL }
+		{ NULL }
 	};
 
