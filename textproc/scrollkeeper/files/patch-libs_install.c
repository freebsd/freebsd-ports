--- libs/install.c.orig	Sat Dec  6 17:47:34 2003
+++ libs/install.c	Sat Dec  6 17:47:47 2003
@@ -517,10 +517,9 @@
     /* these should all be <sect> nodes */	    
     for(node = sect_node; node != NULL; node = node->next)
     {
+	xmlChar *categorycode;
     	if (xmlStrcmp(node->name, (xmlChar *)"sect"))
 	    continue;
-	
-	xmlChar *categorycode;
 	
 	categorycode = xmlGetProp(node, (xmlChar *)"categorycode");
 	if (categorycode == NULL)
