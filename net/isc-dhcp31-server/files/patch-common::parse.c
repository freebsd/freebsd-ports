--- common/parse.c.orig	2 Sep 2003 11:01:23 -0000
+++ common/parse.c	22 Feb 2004 10:44:52 -0000
@@ -414,6 +414,7 @@
 {
 	const char *val;
 	enum dhcp_token token;
+	int32_t num;
 
 	token = next_token (&val, (unsigned *)0, cfile);
 	if (token != NUMBER) {
@@ -421,9 +422,9 @@
 		skip_to_semi (cfile);
 		return;
 	}
-	convert_num (cfile, (unsigned char *)timep, val, 10, 32);
+	convert_num (cfile, (unsigned char *)&num, val, 10, 32);
 	/* Unswap the number - convert_num returns stuff in NBO. */
-	*timep = ntohl (*timep); /* XXX */
+	*timep = ntohl (num);
 
 	parse_semi (cfile);
 }
