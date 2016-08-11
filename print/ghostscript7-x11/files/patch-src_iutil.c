--- src/iutil.c.orig	2003-01-17 00:49:04 UTC
+++ src/iutil.c
@@ -428,7 +428,7 @@ other:
 	data = (const byte *)(op->value.boolval ? "true" : "false");
 	break;
     case t_integer:
-	sprintf(buf, "%ld", op->value.intval);
+	sprintf(buf, "%d", op->value.intval);
 	break;
     case t_string:
 	check_read(*op);
