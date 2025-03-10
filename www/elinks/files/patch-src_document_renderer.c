--- src/document/renderer.c.orig	2024-12-26 11:02:09 UTC
+++ src/document/renderer.c
@@ -415,11 +415,11 @@ struct conv_table *
 }
 
 struct conv_table *
-get_convert_table(char *head, int to_cp,
+get_convert_table(const char *head, int to_cp,
 		  int default_cp, int *from_cp,
 		  enum cp_status *cp_status, int ignore_server_cp)
 {
-	char *part = head;
+	const char *part = head;
 	int cp_index = -1;
 
 	assert(head);
