--- agent/filter/parser.c.orig	2020-04-09 14:16:46 UTC
+++ agent/filter/parser.c
@@ -327,10 +327,7 @@ char *file;
 }
 
 /* VARARGS3 */
-private void check_fatal(flags, reason, arg1, arg2, arg3, arg4, arg5)
-int flags;
-char *reason;
-long arg1, arg2, arg3, arg4, arg5;
+private void check_fatal(int flags, char *reason, char *arg1)
 {
 	/* Die with a fatal error if MAY_PANIC is specified in flags, otherwise
 	 * simply log the error.
@@ -339,10 +336,10 @@ long arg1, arg2, arg3, arg4, arg5;
 	char buffer[MAX_STRING];
 
 	if (flags & MAY_PANIC)
-		fatal(reason, arg1, arg2, arg3, arg4, arg5);
+		fatal(reason, arg1);
 
 	sprintf(buffer, "ERROR %s", reason);
-	add_log(1, buffer, arg1, arg2, arg3, arg4, arg5);
+	add_log(1, buffer, arg1);
 }
 
 private int check_perm(file, flags)
