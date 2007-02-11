--- src/convert_pwdb.c.orig	Tue Feb 14 12:43:20 2006
+++ src/convert_pwdb.c	Mon Feb 12 06:53:53 2007
@@ -186,13 +186,32 @@
 write_password_node(xmlNodePtr root, Pw *pw)
 {
 	xmlNodePtr node;
+	xmlChar *escaped;
+
+	// Take the inbound strings. Treat as an xmlChar, and escape
+	// Need to free the result of escape every time
 
 	node = xmlNewChild(root, NULL, (xmlChar*)"PwItem", NULL);
-	xmlNewChild(node, NULL, (xmlChar*)"name", (xmlChar*)pw->name);
-	xmlNewChild(node, NULL, (xmlChar*)"host", (xmlChar*)pw->host);
-	xmlNewChild(node, NULL, (xmlChar*)"user", (xmlChar*)pw->user);
-	xmlNewChild(node, NULL, (xmlChar*)"passwd", (xmlChar*)pw->passwd);
-	xmlNewChild(node, NULL, (xmlChar*)"launch", (xmlChar*)pw->launch);
+
+	escaped = xmlEncodeSpecialChars(root, (xmlChar*)pw->name);
+	xmlNewChild(node, NULL, (xmlChar*)"name", escaped);
+	xmlFree(escaped);
+
+	escaped = xmlEncodeSpecialChars(root, (xmlChar*)pw->host);
+	xmlNewChild(node, NULL, (xmlChar*)"host", escaped);
+	xmlFree(escaped);
+
+	escaped = xmlEncodeSpecialChars(root, (xmlChar*)pw->user);
+	xmlNewChild(node, NULL, (xmlChar*)"user", escaped);
+	xmlFree(escaped);
+
+	escaped = xmlEncodeSpecialChars(root, (xmlChar*)pw->passwd);
+	xmlNewChild(node, NULL, (xmlChar*)"passwd", escaped);
+	xmlFree(escaped);
+	
+	escaped = xmlEncodeSpecialChars(root, (xmlChar*)pw->launch);
+	xmlNewChild(node, NULL, (xmlChar*)"launch", escaped);
+	xmlFree(escaped);
 }
 
 int
