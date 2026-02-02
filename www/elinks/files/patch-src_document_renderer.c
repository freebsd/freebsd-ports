--- src/document/renderer.c.orig	2025-12-25 11:06:07 UTC
+++ src/document/renderer.c
@@ -657,12 +657,12 @@ struct conv_table *
 }
 
 struct conv_table *
-get_convert_table(char *head, int to_cp,
+get_convert_table(const char *head, int to_cp,
 		  int default_cp, int *from_cp,
 		  enum cp_status *cp_status, int ignore_server_cp)
 {
 	ELOG
-	char *part = head;
+	const char *part = head;
 	int cp_index = -1;
 
 	assert(head);
