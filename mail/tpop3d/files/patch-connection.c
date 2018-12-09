--- connection.c.orig	2008-07-12 13:48:22 UTC
+++ connection.c
@@ -316,7 +316,7 @@ pop3command connection_parsecommand(connection c) {
      * latter case we must be careful not to interpret command1\ncommand2\r\n
      * as a single command. So always use \n as the line ending and strip off
      * any trailing \r. */
-    if (!(p = buffer_consume_to_mark(c->rdb, "\n", 1, line, &llen)))
+    if (!(p = buffer_consume_to_mark(c->rdb, "\n", line, &llen)))
         return NULL;
     else
         line = p;
