--- libs/install.c.orig	Tue Nov  4 02:42:22 2003
+++ libs/install.c	Tue Nov  4 02:42:26 2003
@@ -41,7 +41,7 @@
 static int get_unique_doc_id(char *);
 static void add_doc_to_scrollkeeper_docs(char *, char *, char *, int, char *);
 static void add_doc_to_content_list(xmlNodePtr, char *, char **, char *, char *,
-				    char *, char *, char *, int, int, char);
+				    char *, char *, char *, int, int, char, char **);
 static char *get_doc_property(xmlNodePtr, char *, char *);
 static char *get_doc_parameter_value(xmlNodePtr, char *);
 static char* remove_leading_and_trailing_white_spaces(char *);
@@ -113,6 +113,10 @@
     
     snprintf(command, 1024, "scrollkeeper-get-toc-from-docpath %s", docpath);
     config_fid = popen(command, "r");
+
+    if (config_fid == NULL)
+	return NULL;
+
     fscanf(config_fid, "%s", tocpath);
     if (pclose(config_fid))
         return NULL;
@@ -219,8 +223,13 @@
 	{
 	    /* create full content list path names and read trees */
     	    locale = get_doc_property(node, "language", "code");
-	    if (!get_best_locale_dir(locale_dir, locale_name, scrollkeeper_dir, locale))
+	    if (locale == NULL)
+		continue;
+	    if (!get_best_locale_dir(locale_dir, locale_name, scrollkeeper_dir, locale)) {
+		xmlFree(locale);
 	        continue;
+	    }
+	    xmlFree(locale);
     	    snprintf(cl_filename, PATHLEN, "%s/scrollkeeper_cl.xml", locale_dir);
 	    snprintf(cl_ext_filename, PATHLEN, "%s/scrollkeeper_extended_cl.xml", locale_dir);
 	    
@@ -245,6 +254,8 @@
     	    }
 
 	    docpath = get_doc_property(node, "identifier", "url");
+	    if (docpath == NULL)
+		continue;
 	    
 	    /* add to scrollkeeper_docs */
 	    unique_id = get_unique_doc_id(scrollkeeper_docs);
@@ -252,7 +263,7 @@
 	    					locale_name);
 						
 	    format = get_doc_property(node, "format", "mime");
-	    if (!strcmp(format, "text/xml"))
+	    if (format && !strcmp(format, "text/xml"))
 	    {
 	        /* create TOC file and index file */
 
@@ -304,6 +315,8 @@
 	    }
 	    
 	    uid = get_doc_property(node, "relation", "seriesid");
+	    if (uid == NULL)
+		continue;
 	    
 	    title = get_doc_parameter_value(node, "title");
     	    strncpy(str, title, 1024);
@@ -315,18 +328,25 @@
 	        /* look for subject nodes */
 	        if (!xmlStrcmp(s_node->name, (xmlChar *)"subject"))
 		{
-		    char *category, *token, *rest;
+		    char *category, *token, *rest, *complete_cat_token = NULL;
 
 		    category = (char *)xmlGetProp(s_node, (xmlChar *)"category");
+		    if (category == NULL)
+			continue;
 		    token = strtok_r(category, SEP, &rest);
 		    add_doc_to_content_list(cl_doc->children->children, token, &rest,
-		    docpath, omf_name, title, format, uid, unique_id, 0, outputprefs);
-		    free((void *)category);
+		    docpath, omf_name, title, format, uid, unique_id, 0, outputprefs,
+			&complete_cat_token);
+		    xmlFree(category);
+		    free((void *)complete_cat_token);
 		    category = (char *)xmlGetProp(s_node, (xmlChar *)"category");
 		    token = strtok_r(category, SEP, &rest);
+			complete_cat_token = NULL;
 		    add_doc_to_content_list(cl_ext_doc->children->children, token, &rest,
-		    docpath, omf_name, title, format, uid, unique_id, 1, outputprefs);
-		    free((void *)category);
+		    docpath, omf_name, title, format, uid, unique_id, 1, outputprefs,
+			&complete_cat_token);
+		    xmlFree(category);
+		    free((void *)complete_cat_token);
 		}
 	    }
 	    
@@ -334,6 +354,9 @@
 	    xmlFreeDoc(cl_doc);
 	    xmlSaveFile(cl_ext_filename, cl_ext_doc);
 	    xmlFreeDoc(cl_ext_doc);
+        xmlFree(docpath);
+	xmlFree(format);
+	xmlFree(uid);
 	}
     }
     
@@ -409,6 +432,7 @@
 	    unique_id = id;
     }
 
+   fclose (fid);
    return unique_id + 1;
 }
 
@@ -472,32 +496,38 @@
 static void add_doc_to_content_list(xmlNodePtr sect_node, char *cat_token, char **rest,
 				    char *docpath, char *omf_name,
 				    char *title, char *format, char *uid,
-				    int id, int add_toc, char outputprefs)
+				    int id, int add_toc, char outputprefs, char **complete_cat_token)
 {
-    xmlNodePtr node, new_node, t_node, s_node;
+    xmlNodePtr node, new_node, s_node;
 
     if (sect_node == NULL ||
         cat_token == NULL)
         return;
 
+	if (*complete_cat_token == NULL)
+		*complete_cat_token = strdup(cat_token);
+	else {
+		char *ptr;
+		ptr = malloc(strlen(*complete_cat_token) + strlen(cat_token) + 2);
+		sprintf(ptr, "%s%s", *complete_cat_token, cat_token);
+		free(*complete_cat_token);
+		*complete_cat_token = ptr;
+	}
+
     /* these should all be <sect> nodes */	    
     for(node = sect_node; node != NULL; node = node->next)
     {
     	if (xmlStrcmp(node->name, (xmlChar *)"sect"))
 	    continue;
-	    
-	for(t_node = node->children; t_node != NULL; t_node = t_node->next)
-	{
-    	    /* these should be <title>, <sect> or <doc> nodes */
-            if (t_node->type == XML_ELEMENT_NODE &&
-	        !xmlStrcmp(t_node->name, (xmlChar *)"title"))
-		break;
-	}
+	
+	xmlChar *categorycode;
+	
+	categorycode = xmlGetProp(node, (xmlChar *)"categorycode");
+	if (categorycode == NULL)
+	    continue;
 	
 	/* these should be the actual titles */
-	if (t_node != NULL && t_node->children != NULL &&
-	    t_node->children->type == XML_TEXT_NODE &&
-	    !xmlStrcmp((xmlChar *)cat_token, t_node->children->content))
+	if (!xmlStrcmp((xmlChar *)(*complete_cat_token), categorycode))
 	{
 	        cat_token = strtok_r(NULL, SEP, rest);
 		if (cat_token == NULL)
@@ -536,9 +566,11 @@
 		    if (s_node != NULL)
 		        add_doc_to_content_list(s_node, cat_token, rest, 
 						docpath, omf_name, title, format,
-						uid, id, add_toc, outputprefs);
+						uid, id, add_toc, outputprefs, complete_cat_token);
 		    return;
 		}
 	}	
+	
+	xmlFree(categorycode);
     }
 }
