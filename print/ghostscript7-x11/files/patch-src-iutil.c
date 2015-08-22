--- src/iutil.c.orig	2013-04-30 10:51:05.000000000 +0900
+++ src/iutil.c	2013-04-30 10:51:20.000000000 +0900
@@ -428,7 +428,7 @@
 	data = (const byte *)(op->value.boolval ? "true" : "false");
 	break;
     case t_integer:
-	sprintf(buf, "%ld", op->value.intval);
+	sprintf(buf, "%d", op->value.intval);
 	break;
     case t_string:
 	check_read(*op);
