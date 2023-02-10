--- src/protocol/header.c.orig	2022-12-25 18:17:02 UTC
+++ src/protocol/header.c
@@ -141,9 +141,9 @@ char *
  * The terms message-header, field-name, start-line, and field-content
  * are defined in RFC 2616 sections 4.1 and 4.2.  */
 char *
-parse_header(char *head, const char *item, char **ptr)
+parse_header(const char *head, const char *item, const char **ptr)
 {
-	char *pos = head;
+	const char *pos = head;
 
 	if (!pos) return NULL;
 
