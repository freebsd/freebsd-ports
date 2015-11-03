--- common/cmd_test.c.orig	2015-10-19 23:59:38 UTC
+++ common/cmd_test.c
@@ -56,9 +56,14 @@ static int do_test(cmd_tbl_t *cmdtp, int
 	char * const *ap;
 	int i, op, left, adv, expr, last_expr, last_unop, last_binop;
 
-	/* args? */
-	if (argc < 3)
+	/*
+	 * If no args, that's bogus, return false.
+	 * If op is -z and no other args, answer is Yes, string is empty.
+	 */
+	if (argc < 2)
 		return 1;
+	else if (argc == 2)
+		return !(strcmp(argv[1], "-z") == 0);
 
 #ifdef DEBUG
 	{
