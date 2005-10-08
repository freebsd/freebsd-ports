--- src/pwlist.c.old	2005-03-09 16:07:07.000000000 +0000
+++ src/pwlist.c	2005-03-09 16:06:37.000000000 +0000
@@ -272,13 +272,32 @@
 write_password_node(xmlNodePtr root, Pw* pw)
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
