--- lib/cfparse.y-	2013-12-21 11:29:53.328819029 +0900
+++ lib/cfparse.y	2013-12-21 11:30:25.058283579 +0900
@@ -1712,7 +1712,7 @@
 	int n;
 	char *bp;
 	struct cf_list *new;
-	rcf_t type;
+	rc_type type;
 
 	n = strtoll(str, &bp, 10);
 
