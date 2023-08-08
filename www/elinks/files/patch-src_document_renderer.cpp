--- src/document/renderer.cpp.orig	2022-12-25 18:17:02 UTC
+++ src/document/renderer.cpp
@@ -615,11 +615,11 @@ struct conv_table *
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
