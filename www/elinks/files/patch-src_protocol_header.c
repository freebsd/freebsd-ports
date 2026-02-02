--- src/protocol/header.c.orig	2025-12-25 11:06:07 UTC
+++ src/protocol/header.c
@@ -141,10 +141,10 @@ char *
  * The terms message-header, field-name, start-line, and field-content
  * are defined in RFC 2616 sections 4.1 and 4.2.  */
 char *
-parse_header(char *head, const char *item, char **ptr)
+parse_header(const char *head, const char *item, const char **ptr)
 {
 	ELOG
-	char *pos = head;
+	const char *pos = head;
 
 	if (!pos) return NULL;
 
